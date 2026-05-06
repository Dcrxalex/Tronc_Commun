/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:48:09 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/06 16:48:09 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	if (ac < 2)
		return (0);
	if (!is_valid(av))
		return (1);
	a = build_stack(av);
	b = NULL;
	if (is_sorted(a))
		return (0);
	return (0);
}
