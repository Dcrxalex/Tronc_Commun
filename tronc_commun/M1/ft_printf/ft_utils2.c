/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:58:59 by aldecro           #+#    #+#             */
/*   Updated: 2026/04/20 10:59:13 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	help_int(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
		return (ft_putchar('-') + help_int(-n));
	if (n < 10)
		return (ft_putchar('0' + n));
	return (help_int(n / 10) + ft_putchar('0' + (n % 10)));
}

int	help_unsigned(unsigned int n)
{
	if (n < 10)
		return (ft_putchar('0' + n));
	return (help_unsigned(n / 10) + ft_putchar('0' + (n % 10)));
}

int	help_hex(unsigned long n, int uppercase)
{
	char	*base;

	if (uppercase == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < 16)
		return (ft_putchar(base[n]));
	return (help_hex(n / 16, uppercase) + ft_putchar(base[n % 16]));
}

int	help_pointer(unsigned long n)
{
	return (write(1, "0x", 2) + help_hex(n, 0));
}
