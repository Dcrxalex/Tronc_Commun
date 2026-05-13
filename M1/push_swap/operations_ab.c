/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:58:20 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/11 10:58:20 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **lst)
{
	swap(lst);
	write(1, "sa\n", 3);
}

void	sb(t_stack **lst)
{
	swap(lst);
	write(1, "sb\n", 3);
}

void	ra(t_stack **lst)
{
	rotate(lst);
	write(1, "ra\n", 3);
}

void	rb(t_stack **lst)
{
	rotate(lst);
	write(1, "rb\n", 3);
}
