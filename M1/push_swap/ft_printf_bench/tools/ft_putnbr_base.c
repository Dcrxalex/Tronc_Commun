/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 09:45:00 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/04/23 14:30:43 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <unistd.h>

static int	ft_putnbr_base_recursive(unsigned long long nbr, char *base, \
			unsigned long long len, int print_length)
{
	int	test;

	if (nbr >= len)
	{
		test = ft_putnbr_base_recursive(nbr / len, base, len, print_length + 1);
		if (print_length < test)
			print_length = test;
	}
	ft_putchar_fd(base[nbr % len], 2);
	return (print_length);
}

static int	ft_putnbr_help(int type, t_flags *flags, unsigned long long nbr, \
							char *base)
{
	unsigned long long	len;
	int					print_length;

	print_length = 1;
	len = ft_strlen(base);
	if (type == 'p' && flags->plus == 1)
	{
		ft_putstr_fd("+0x", 2);
		return (ft_putnbr_base_recursive(nbr, base, len, print_length) + 3);
	}
	if (type == 'p' && flags->space == 1)
	{
		ft_putstr_fd(" 0x", 2);
		return (ft_putnbr_base_recursive(nbr, base, len, print_length) + 3);
	}
	ft_putstr_fd("0x", 2);
	return (ft_putnbr_base_recursive(nbr, base, len, print_length) + 2);
}

int	ft_putnbr_base(unsigned long long nbr, char *base, int type, t_flags *flags)
{
	unsigned long long	len;
	int					print_length;

	print_length = 1;
	len = ft_strlen(base);
	if (type == 'p' && nbr == 0)
	{
		ft_putstr_fd("(nil)", 2);
		return (5);
	}
	else if (type == 'p' || (flags->hashtag == 1 && type == 'x' && nbr != 0))
	{
		return (ft_putnbr_help(type, flags, nbr, base));
	}
	else if (flags->hashtag == 1 && nbr != 0)
	{
		ft_putstr_fd("0X", 2);
		return (ft_putnbr_base_recursive(nbr, base, len, print_length) + 2);
	}
	else
		return (ft_putnbr_base_recursive(nbr, base, len, print_length));
}
/*
int	main(void)
{
	ft_putnbr_base(168, "0123456789ABCDEF");
	return (0);
}*/
