/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecroi <aldecroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:46:23 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/13 10:36:19 by aldecroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **lst)
{
	t_stack	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}

void	rotate(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	last = ft_lstlast(*lst);
	last->next = tmp;
}

void	rev_rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*sec_last;

	last = ft_lstlast(*lst);
	sec_last = *lst;
	while (sec_last->next->next != NULL)
		sec_last = sec_last->next;
	sec_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	pb(t_stack **a, t_stack **b, t_flags **flags)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if ((*flags)->print)
		write(1, "pb\n", 3);
	if ((*flags)->bench)
		(*flags)->bench->totl_pb += 1;
}

void	pa(t_stack **a, t_stack **b, t_flags **flags)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if ((*flags)->print)
		write(1, "pa\n", 3);
	if ((*flags)->bench)
		(*flags)->bench->totl_pa += 1;
}
