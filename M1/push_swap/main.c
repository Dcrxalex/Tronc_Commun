/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:37:26 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/05/07 15:26:58 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flags	*flags_malloc(t_flags *flags)
{
	flags = malloc(sizeof(t_flags));
	if (!flags)
		ft_error();
	return (flags);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_flags	*flags;

	stack_a = NULL;
	flags = NULL;
	flags = flags_malloc(flags);
	if (argc == 1)
		ft_error ();
	ft_sort_create(argv + 1, &stack_a, &flags);
	if (is_sorted(stack_a))
		return (0);
	sortit(&stack_a, &flags);
	ft_lstclear(&stack_a);
	free(flags);
	return (0);
}
