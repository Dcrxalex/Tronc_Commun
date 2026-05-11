/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:58:58 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/11 15:34:40 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	pos;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	while (stack_size(*a) > 3)
	{
		pos = find_min_pos(*a);
		if (pos <= stack_size(*a) / 2)
		{
			while (pos--)
				ra(a);
		}
		else
		{
			pos = (stack_size(*a) - pos);
			while (pos--)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
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

void	sort_three(t_stack **a)
{
	int	first;
	int	sec;
	int	third;

	first = (*a)->value;
	sec = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > sec && first > third)//if a is bigger than b and a is bigger than c
	{
		if (sec > third)//if b is bigger than c do sa then rra				(3 2 1)
		{
			sa(a);
			rra(a);
		}
		else if (third > sec)	//elseif c is bigger than b do ra				(3 1 2)
			ra(a);
	}
	else if (sec > first && sec > third)//if b is bigger than a and b is bigger than c
	{
		if (first > third)//if a bigger than c do rra							(2 3 1)
			rra(a);
		else if (third > first)//else if c is bigger than a do sa then do ra		(1 3 2)
		{
			sa(a);
			ra(a);
		}
	}
	else if (third > sec && third > first)// if c is bigger than a and c is bigger than b
	{
		if (first > sec)//if a is bigger than b do sa						(2 1 3)
			sa(a);
	}
		//else if b is bigger than a do nothing				(1 2 3)
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

void	sort_b(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	pos = find_max_pos(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
		while (pos--)
			rb (b);
	else
	{
		pos = size - pos;
		while (pos--)
			rrb(b);
	}
	pa(a, b);
}
