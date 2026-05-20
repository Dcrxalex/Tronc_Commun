/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecroi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:20:47 by aldecroi          #+#    #+#             */
/*   Updated: 2026/05/13 10:20:49 by aldecroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(a);
	swap(b);
	if ((*flags)->print)
		write(1, "ss\n", 3);
	if ((*flags)->bench)
		(*flags)->bench->totl_ss += 1;
}

void	rr(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(a);
	rotate(b);
	if ((*flags)->print)
		write(1, "rr\n", 3);
	if ((*flags)->bench)
		(*flags)->bench->totl_rr += 1;
}

void	rra(t_stack **lst, t_flags **flags)
{
	rev_rotate(lst);
	if ((*flags)->print)
		write(1, "rra\n", 4);
	if ((*flags)->bench)
		(*flags)->bench->totl_rra += 1;
}

void	rrb(t_stack **lst, t_flags **flags)
{
	rev_rotate(lst);
	if ((*flags)->print)
		write(1, "rrb\n", 4);
	if ((*flags)->bench)
		(*flags)->bench->totl_rrb += 1;
}

void	rrr(t_stack **a, t_stack **b, t_flags **flags)
{
	rev_rotate(a);
	rev_rotate(b);
	if ((*flags)->print)
		write(1, "rrr\n", 4);
	if ((*flags)->bench)
		(*flags)->bench->totl_rrr += 1;
}
