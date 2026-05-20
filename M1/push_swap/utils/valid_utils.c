#include "../push_swap.h"

int	is_sorted(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

void	is_validAndFlags(char **av, t_flags **flags)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' && av[i][j + 1] == '-')
		{
			j = flags_check(flags, av[i]);
			if (av[i][j] == '-')
				error_freeargv(av, *flags);
		}
		else if (((av[i][j] == '+' || av[i][j] == '-') && ft_isdigit(av[i][j
					+ 1])) || ft_isdigit(av[i][j]))
			j++;
		else
			error_freeargv(av, *flags);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				error_freeargv(av, *flags);
			j++;
		}
		i++;
	}
}

int	check_same_nbr(t_stack **stack_a)
{
	t_stack *curr;
	t_stack *runner;

	curr = *stack_a;
	while (curr)
	{
		runner = curr->next;
		while (runner)
		{
			if (curr->value == runner->value)
			{
				ft_lstclear(stack_a);
				return (-1);
			}
			runner = runner->next;
		}
		curr = curr->next;
	}
	return (1);
}