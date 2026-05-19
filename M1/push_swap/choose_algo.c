/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 00:00:00 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/15 00:00:00 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	init_flags(t_flags *flags)
{
	flags->simple = 0;
	flags->medium = 0;
	flags->is_complex = 0;
	flags->adaptive = 0;
	flags->bench = 0;
}

int	parse_flags(char **av, t_flags *flags)
{
	int	i;

	i = 0;
	init_flags(flags);
	while (av[i] && av[i][0] == '-' && av[i][1] == '-')
	{
		if (ft_strcmp(av[i], "--simple") == 0)
			flags->simple = 1;
		else if (ft_strcmp(av[i], "--medium") == 0)
			flags->medium = 1;
		else if (ft_strcmp(av[i], "--complex") == 0)
			flags->is_complex = 1;
		else if (ft_strcmp(av[i], "--adaptive") == 0)
			flags->adaptive = 1;
		else if (ft_strcmp(av[i], "--bench") == 0)
			flags->bench = 1;
		i++;
	}
	return (i);
}

void	sortit(t_stack **a, t_stack **b, t_flags *flags)
{
	if (flags->simple)
		simple_sort(a, b);
	else
		medium_sort(a, b);
}
