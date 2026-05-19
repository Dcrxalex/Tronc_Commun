/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:58:58 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/15 21:48:16 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *lst)
{
	int	pos;
	int	min;
	int	i;

	pos = 0;
	i = 0;
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
	int	pos;
	int	max;

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

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && top < bot)
		sa(a);
	else if (top > mid && top > bot && mid < bot)
		ra(a);
	else if (mid > top && top > bot)
		rra(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (mid > bot && bot > top)
	{
		rra(a);
		sa(a);
	}
}

void	sort_b(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	pos = find_max_pos(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
		while (pos--)
			rb(b);
	else
	{
		pos = size - pos;
		while (pos--)
			rrb(b);
	}
	pa(a, b);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	if (stack_size(*a) <= 1)
		return ;
	else if (stack_size(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	while (stack_size(*a) > 3)
	{
		rotate_to_pos(a, find_min_pos(*a));
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
