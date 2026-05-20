/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:27:18 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/05/18 16:27:20 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	all_calculation_movement_b(t_stack **b, t_stack **a, \
		t_flags **flags)
{
	calcul_pos(b);
	calcul_pos(a);
	search_target_b(b, a);
	calcul_cost(b);
	search_cheapest(b);
	turn_b(b, a, flags);
	pa(a, b, flags);
}

static void	all_calculation_movement_a(t_stack **a, t_stack **b, \
		t_flags **flags)
{
	calcul_pos(a);
	calcul_pos(b);
	search_target_a(a, b);
	calcul_cost(a);
	search_cheapest(a);
	turn_a(a, b, flags);
	pb(a, b, flags);
}

static void	shift_stack_a(t_stack **a, t_flags **flags)
{
	t_stack	*min;
	t_stack	*temp;

	calcul_pos(a);
	min = *a;
	temp = *a;
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	while ((*a)->value != min->value)
	{
		if (min->median == 1)
			ra(a, flags);
		else
			rra(a, flags);
	}
}

void	complex_sort(t_stack **a, t_stack **b, t_flags **flags)
{
	long	size;

	size = stack_size(*a);
	if (size == 2 && (*a)->value > (*a)->next->value)
	{
		sa(a, flags);
		return ;
	}
	if (size > 3)
	{
		pb(a, b, flags);
		size--;
	}
	if (size > 3 && !is_sorted(*a))
	{
		pb(a, b, flags);
		size--;
	}
	while (size-- > 3)
		all_calculation_movement_a(a, b, flags);
	sort_three(a, flags);
	while (*b)
		all_calculation_movement_b(b, a, flags);
	shift_stack_a(a, flags);
}
