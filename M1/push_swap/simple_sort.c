/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecroi <aldecroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:58:58 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/13 10:30:51 by aldecroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **a, t_stack **b, t_flags **flags)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (stack_size(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, flags);
		return ;
	}
	while (stack_size(*a) > 3)
	{
		rotate_to_pos(a, find_min_pos(*a), flags);
		pb(a, b, flags);
	}
	sort_three(a, flags);
	while (*b)
		pa(a, b, flags);
}

int	find_min_pos(t_stack *lst)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	pos = 0;
	min = lst->value;
	while (lst)
	{
		if (lst->value < min)
		{
			pos = i;
			min = lst->value;
		}
		i++;
		lst = lst->next;
	}
	return (pos);
}

int	find_max_pos(t_stack *lst)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	pos = 0;
	max = lst->value;
	while (lst)
	{
		if (lst->value > max)
		{
			pos = i;
			max = lst->value;
		}
		i++;
		lst = lst->next;
	}
	return (pos);
}

void	sort_three(t_stack **a, t_flags **flags)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && top < bot) // 2 1 3
		sa(a, flags);
	else if (top > mid && top > bot && mid < bot) // 3 1 2
		ra(a, flags);
	else if (top > mid && top > bot && mid > bot) // 3 2 1
	{
		sa(a, flags);
		rra(a, flags);
	}
	else if (top < mid && top < bot && mid > bot) // 1 3 2
	{
		sa(a, flags);
		ra(a, flags);
	}
	else if (top < mid && top > bot) // 2 3 1
		rra(a, flags);
}

// void	sort_b(t_stack **a, t_stack **b, t_flags **flags)
//{
//	int	pos;
//	int	size;

//	pos = find_max_pos(*b);
//	size = stack_size(*b);
//	if (pos <= size / 2)
//		while (pos--)
//			rb(b, flags);
//	else
//	{
//		pos = size - pos;
//		while (pos--)
//			rrb(b, flags);
//	}
//	pa(a, b, flags);
//}