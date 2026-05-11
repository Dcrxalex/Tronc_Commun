/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:48:09 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/09 17:32:28 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		start;

	if (ac < 2)
		return (0);
	start = 1;
	if (!is_valid(av + start))
		return (1);
	if (is_dup(av + start))
		return (1);
	a = build_stack(av);
	b = NULL;
	if (is_sorted(a))
		return (0);
	simple_sort(&a, &b);
	return (0);
}
