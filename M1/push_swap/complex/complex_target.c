/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:26:54 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/05/18 16:26:56 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	search_target_init(t_stack **target, t_stack **original,
		t_stack **max_min, t_stack **temp)
{
	(*target) = NULL;
	(*max_min) = (*original);
	(*temp) = (*original);
}

static void	search_target_check(t_stack **target, t_stack **temp,
		t_stack **max_min)
{
	if (!(*target))
		(*temp)->target = (*max_min);
	else
		(*temp)->target = (*target);
	(*temp) = (*temp)->next;
}

void	search_target_b(t_stack **b, t_stack **a)
{
	t_stack	*target;
	t_stack	*a_temp;
	t_stack	*b_temp;
	t_stack	*min;
	long		closest_larger;

	b_temp = *b;
	while (b_temp)
	{
		closest_larger = 2147483648;
		search_target_init(&target, a, &min, &a_temp);
		while (a_temp)
		{
			if (a_temp->value > b_temp->value && a_temp->value < closest_larger)
			{
				closest_larger = a_temp->value;
				target = a_temp;
			}
			if (a_temp->value < min->value)
				min = a_temp;
			a_temp = a_temp->next;
		}
		search_target_check(&target, &b_temp, &min);
	}
}

void	search_target_a(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*b_temp;
	t_stack	*a_temp;
	t_stack	*max;
	long		closest_smaller;

	a_temp = *a;
	while (a_temp)
	{
		closest_smaller = -2147483649;
		search_target_init(&target, b, &max, &b_temp);
		while (b_temp)
		{
			if (b_temp->value < a_temp->value
				&& b_temp->value > closest_smaller)
			{
				closest_smaller = b_temp->value;
				target = b_temp;
			}
			if (b_temp->value > max->value)
				max = b_temp;
			b_temp = b_temp->next;
		}
		search_target_check(&target, &a_temp, &max);
	}
}
