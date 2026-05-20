/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecroi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:21:15 by aldecroi          #+#    #+#             */
/*   Updated: 2026/05/13 10:21:16 by aldecroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **lst, t_flags **flags)
{
	swap(lst);
	if ((*flags)->print)
		write(1, "sa\n", 3);
	if ((*flags)->bench)
		(*flags)->bench->totl_sa += 1;
}

void	sb(t_stack **lst, t_flags **flags)
{
	swap(lst);
	if ((*flags)->print)
		write(1, "sb\n", 3);
	if ((*flags)->bench)
		(*flags)->bench->totl_sb += 1;
}

void	ra(t_stack **lst, t_flags **flags)
{
	rotate(lst);
	if ((*flags)->print)
		write(1, "ra\n", 3);
	if ((*flags)->bench)
		(*flags)->bench->totl_ra += 1;
}

void	rb(t_stack **lst, t_flags **flags)
{
	rotate(lst);
	if ((*flags)->print)
		write(1, "rb\n", 3);
	if ((*flags)->bench)
		(*flags)->bench->totl_rb += 1;
}
