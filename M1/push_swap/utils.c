/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:19:37 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/11 10:58:20 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	n;
	int		i;
	int		sign;

	n = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * sign);
}

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	set_rank(t_stack *a)
{
	t_stack	*curr;
	t_stack	*scan;
	int		rank;

	curr = a;
	while (curr)
	{
		rank = 0;
		scan = a;
		while (scan)
		{
			if (curr->value > scan->value)
				rank++;
			scan = scan->next;
		}
		curr->rank = rank;
		curr = curr->next;
	}
}

void	free_stack(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	rotate_to_pos(t_stack **a, int pos)
{
	int	size;

	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos--)
			ra(a);
	else
	{
		pos = size - pos;
		while (pos--)
			rra(a);
	}
}
