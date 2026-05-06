/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:46:23 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/06 18:25:14 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(t_stack **lst)
{
	t_stack *tmp;

	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}

void	rotate(t_stack **lst)
{
	t_stack *tmp;
	t_stack *last;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	last = ft_last(*lst);
	last->next = tmp;
}

void	rev_rotate(t_stack **lst)
{
	t_stack *last;
	t_stack *sec_last;

	last = ft_last(*lst);
	sec_last = *lst;
	while (sec_last->next->next != NULL)
		sec_last = sec_last->next;
	sec_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

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

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
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

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack **lst)
{
	rev_rotate(lst);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **lst)
{
	rev_rotate(lst);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}
