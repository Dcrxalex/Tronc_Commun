#include "./../push_swap.h"
#include "checker.h"

static void	check_stack(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ft_checker_error(t_stack **a, t_stack **b, char *command, t_flags **flags)
{
	ft_lstclear(a);
	ft_lstclear(b);
	free(command);
	free((*flags));
	ft_error();
}

static void	checker(t_stack **a, t_stack **b, t_flags **flags)
{
	char	*command;

	command = get_next_line(0);
	while (command != NULL)
	{
		if (checker_s_oper(a, b, flags, command) || \
			checker_r_oper(a, b, flags, command) || \
			checker_rr_oper(a, b, flags, command) || \
			checker_push_oper(a, b, flags, command))
			free(command);
		else
			ft_checker_error(a, b, command, flags);
		command = get_next_line(0);
	}
	check_stack(*a, *b);
}

static t_flags	*flags_malloc(t_flags *flags)
{
	flags = malloc(sizeof(t_flags));
	if (!flags)
		ft_error();
	flags->disorder = 0;
	flags->print = 0;
	flags->bench = NULL;
	flags_to_zero(&flags);
	return (flags);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_flags	*flags;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	flags = NULL;
	if (argc == 1)
		return (0);
	flags = flags_malloc(flags);
	ft_sort_create(argv + 1, &stack_a, &flags);
	checker(&stack_a, &stack_b, &flags);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	free(flags);
	return (0);
}
