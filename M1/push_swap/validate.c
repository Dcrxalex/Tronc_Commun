/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:11:32 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/15 22:24:03 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

static int	is_valid_arg(char *arg)
{
	int		j;
	long	n;

	j = 0;
	if (arg[j] == '+' || arg[j] == '-')
		j++;
	if (!arg[j])
		return (error());
	while (arg[j])
	{
		if (arg[j] < '0' || arg[j] > '9')
			return (error());
		j++;
	}
	n = ft_atol(arg);
	if (n < -2147483648 || n > 2147483647)
		return (error());
	return (1);
}

int	is_valid(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_valid_arg(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(char **av)
{
	int		i;
	int		j;
	long	vi;

	i = 0;
	while (av[i])
	{
		vi = ft_atol(av[i]);
		j = i + 1;
		while (av[j])
		{
			if (vi == ft_atol(av[j]))
			{
				error();
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
