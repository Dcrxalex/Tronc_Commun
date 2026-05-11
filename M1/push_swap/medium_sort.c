/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:33:30 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/11 15:37:02 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rank(t_stack *a)
{
	t_stack	*curr;
	t_stack	*scan;
	int		rank;

	curr = a;
	while(curr)
	{
		rank = 0;
		scan = a;
		while (scan)
		{
			if (curr->value > scan->value)
				rank++;
			scan = scan->next;
		}
		curr->rank = rank;
		curr = curr->next;
	}
}

int	ft_sqrt(int	n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int	chunk_has_nodes(t_stack *lst, int threshold, int chunk_size)
{
	while (lst)
	{
		if (lst->rank < threshold && lst->rank >= threshold - chunk_size)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	find_best_chunk(t_stack *lst, int threshold, int chunk_size)
{
	int	i;
	int	best_pos;
	int	best_cost;
	int	size;
	int	cost;

	i = 0;
	best_pos = -1;
	size = stack_size(lst);
	best_cost = size;
	while (lst)
	{
		if (lst->rank < threshold && lst->rank >= threshold - chunk_size)
		{
			if (i <= size / 2)
				cost = i;
			else
				cost = size - i;
			if (cost < best_cost)
			{
				best_cost = cost;
				best_pos = i;
			}
		}
		i++;
		lst = lst->next;
	}
	return (best_pos);
}

void	medium_sort(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	threshold;
	int	size;
	int	pos;

	if (stack_size(*a) <= 1)
		return ;
	set_rank(*a);
	chunk_size = ft_sqrt(stack_size(*a));
	threshold = chunk_size;
	while (*a)
	{
		while (chunk_has_nodes(*a, threshold, chunk_size))
		{
			size = stack_size(*a);
			pos = find_best_chunk(*a, threshold, chunk_size);
			if (pos <= size / 2)
			{
				while (pos--)
					ra(a);
			}
			else
			{
				pos = size - pos;
				while (pos--)
					rra(a);
			}
			pb(a, b);
		}
		threshold += chunk_size;
	}
	while (*b)
		sort_b(a, b);
}
