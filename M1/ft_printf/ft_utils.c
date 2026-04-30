/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 09:54:39 by aldecro           #+#    #+#             */
/*   Updated: 2026/04/20 11:17:33 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	help_char(int c)
{
	ft_putchar(c);
	return (1);
}

int	help_perc(void)
{
	return (ft_putchar('%'));
}

int	help_str(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}
