#include "./../push_swap.h"

int     checker_s_oper(t_stack **a, t_stack **b, t_flags **flags, char *command)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
	{
		if (stack_size(*a) > 1)
			sa(a, flags);
		return (1);
	}
	else if (ft_strncmp(command, "sb\n", 3) == 0)
	{
		if (stack_size(*b) > 1)
			sb(b, flags);
		return (1);
	}
	else if (ft_strncmp(command, "ss\n", 3) == 0)
	{
		if (stack_size(*a) > 1 && stack_size(*b) > 1)
			ss(a, b, flags);
		return (1);
	}
	else
		return (0);
}

int     checker_r_oper(t_stack **a, t_stack **b, t_flags **flags, char *command)
{
	if (ft_strncmp(command, "ra\n", 3) == 0)
	{
		if (stack_size(*a) > 1)
			ra(a, flags);
		return (1);
	}
	else if (ft_strncmp(command, "rb\n", 3) == 0)
	{
		if (stack_size(*b) > 1)
			rb(b, flags);
		return (1);
	}
	else if (ft_strncmp(command, "rr\n", 3) == 0)
	{
		if (stack_size(*a) > 1 && stack_size(*b) > 1)
			rr(a, b, flags);
		return (1);
	}
	else
		return(0);
}

int     checker_rr_oper(t_stack **a, t_stack **b, t_flags **flags, char *command)
{
	if (ft_strncmp(command, "rra\n", 4) == 0)
	{
		if (stack_size(*a) > 1)
			rra(a, flags);
		return (1);
	}
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
	{
		if (stack_size(*b) > 1)
			rrb(b, flags);
		return (1);
	}
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
	{
		if (stack_size(*a) > 1 && stack_size(*b) > 1)
			rrr(a, b, flags);
		return (1);
	}
	else
		return (0);
}

int     checker_push_oper(t_stack **a, t_stack **b, t_flags **flags, char *command)
{
	if (ft_strncmp(command, "pb\n", 3) == 0)
	{
		if (stack_size(*a) > 0)
			pb(a, b, flags);
		return (1);
	}
	else if (ft_strncmp(command, "pa\n", 3) == 0)
	{
		if (stack_size(*b) > 0)
			pa(a, b, flags);
		return (1);
	}
	else
		return (0);
}