/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 09:49:02 by aldecro           #+#    #+#             */
/*   Updated: 2026/04/20 10:56:59 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conv(char c, va_list *ap)
{
	if (c == 'c')
		return (help_char(va_arg(*ap, int)));
	else if (c == 's')
		return (help_str(va_arg(*ap, char *)));
	else if (c == 'p')
		return (help_pointer((unsigned long)va_arg(*ap, void *)));
	else if (c == 'd')
		return (help_int(va_arg(*ap, int)));
	else if (c == 'i')
		return (help_int(va_arg(*ap, int)));
	else if (c == 'u')
		return (help_unsigned(va_arg(*ap, unsigned int)));
	else if (c == 'x')
		return (help_hex(va_arg(*ap, unsigned int), 0));
	else if (c == 'X')
		return (help_hex(va_arg(*ap, unsigned int), 1));
	else if (c == '%')
		return (help_perc());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += handle_conv(format[i + 1], &ap);
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			count++;
		}
	}
	va_end(ap);
	return (count);
}
