/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_calcul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:26:22 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/05/18 16:26:34 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	search_cheapest(t_stack **stack)
{
	t_stack	*cheapest;
	t_stack	*temp;

	temp = *stack;
	cheapest = *stack;
	while (temp)
	{
		temp->cheapest = 0;
		if (cheapest->cost > temp->cost)
			cheapest = temp;
		temp = temp->next;
	}
	cheapest->cheapest = 1;
}

void	calcul_cost(t_stack **stack)
{
	t_stack	*target;
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		target = temp->target;
		if (temp->median == target->median)
		{
			if (temp->position > target->position)
				temp->cost = temp->position;
			else
				temp->cost = target->position;
		}
		else
			temp->cost = temp->position + target->position;
		temp = temp->next;
	}
}

void	calcul_pos(t_stack **stack)
{
	long	size;
	long	i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	size = stack_size(*stack);
	while (temp)
	{
		temp->cost = 0;
		if (i <= size / 2)
		{
			temp->median = 1;
			temp->position = i;
		}
		else
		{
			temp->position = size - i;
			temp->median = 0;
		}
		i++;
		temp = temp->next;
	}
}
