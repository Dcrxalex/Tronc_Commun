/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:33:30 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/11 10:58:20 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compute_cost(int i, int size)
{
	if (i <= size / 2)
		return (i);
	return (size - i);
}

static int	chunk_has_nodes(t_stack *lst, int threshold, int chunk_size)
{
	while (lst)
	{
		if (lst->rank >= threshold - chunk_size && lst->rank < threshold)
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

	i = 0;
	best_pos = -1;
	size = stack_size(lst);
	best_cost = size;
	while (lst)
	{
		if (lst->rank >= threshold - chunk_size && lst->rank < threshold)
		{
			if (compute_cost(i, size) < best_cost)
			{
				best_cost = compute_cost(i, size);
				best_pos = i;
			}
		}
		i++;
		lst = lst->next;
	}
	return (best_pos);
}

static void	push_chunk(t_stack **a, t_stack **b, int threshold, int chunk_size)
{
	int	pos;

	while (chunk_has_nodes(*a, threshold, chunk_size))
	{
		pos = find_best_chunk(*a, threshold, chunk_size);
		rotate_to_pos(a, pos);
		pb(a, b);
	}
}

void	medium_sort(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	threshold;

	if (stack_size(*a) <= 1)
		return ;
	set_rank(*a);
	chunk_size = ft_sqrt(stack_size(*a));
	threshold = chunk_size;
	while (*a)
	{
		push_chunk(a, b, threshold, chunk_size);
		threshold += chunk_size;
	}
	while (*b)
		sort_b(a, b);
}
