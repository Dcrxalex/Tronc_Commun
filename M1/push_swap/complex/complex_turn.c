/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:27:06 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/05/18 16:27:08 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	turn_init(t_stack **temp, t_stack **target, long *pos_target, \
		long *pos)
{
	while ((*temp)->cheapest != 1)
		(*temp) = (*temp)->next;
	(*target) = (*temp)->target;
	*pos_target = (*target)->position;
	*pos = (*temp)->position;
}

static void	turn_rb_rrb(t_stack **temp, long *pos, t_stack **b, t_flags **flags)
{
	if ((*temp)->median == 1 && *pos > 0)
	{
		while ((*pos)-- > 0)
			rb(b, flags);
	}
	if ((*temp)->median == 0 && *pos > 0)
	{
		while ((*pos)-- > 0)
			rrb(b, flags);
	}
}

static void	turn_ra_rra(t_stack **temp, long *pos, t_stack **a, t_flags **flags)
{
	if ((*temp)->median == 1 && *pos > 0)
	{
		while ((*pos)-- > 0)
			ra(a, flags);
	}
	if ((*temp)->median == 0 && *pos > 0)
	{
		while ((*pos)-- > 0)
			rra(a, flags);
	}
}

void	turn_b(t_stack **b, t_stack **a, t_flags **flags)
{
	t_stack	*target;
	t_stack	*b_temp;
	long	pos_b;
	long	pos_target;

	b_temp = *b;
	turn_init(&b_temp, &target, &pos_target, &pos_b);
	while (b_temp->median == 1 && b_temp->median == target->median && pos_b > 0 \
		&& pos_target > 0)
	{
		rr(b, a, flags);
		pos_b--;
		pos_target--;
	}
	while (b_temp->median == 0 && b_temp->median == target->median && pos_b > 0 \
		&& pos_target > 0)
	{
		rrr(b, a, flags);
		pos_b--;
		pos_target--;
	}
	turn_rb_rrb(&b_temp, &pos_b, b, flags);
	turn_ra_rra(&target, &pos_target, a, flags);
}

void	turn_a(t_stack **a, t_stack **b, t_flags **flags)
{
	t_stack	*target;
	t_stack	*a_temp;
	long	pos_a;
	long	pos_target;

	a_temp = *a;
	turn_init(&a_temp, &target, &pos_target, &pos_a);
	while (a_temp->median == 1 && a_temp->median == target->median && pos_a > 0 \
		&& pos_target > 0)
	{
		rr(a, b, flags);
		pos_a--;
		pos_target--;
	}
	while (a_temp->median == 0 && a_temp->median == target->median && pos_a > 0 \
		&& pos_target > 0)
	{
		rrr(a, b, flags);
		pos_a--;
		pos_target--;
	}
	turn_ra_rra(&a_temp, &pos_a, a, flags);
	turn_rb_rrb(&target, &pos_target, b, flags);
}
