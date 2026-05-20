#include "../push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	if (!*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

void	error_freeargv(char **argv, t_flags *flags)
{
	freeargv(argv);
	free(flags);
	ft_error();
}

void	freeargv(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	while (i >= 0)
		free(argv[i--]);
	free(argv);
}