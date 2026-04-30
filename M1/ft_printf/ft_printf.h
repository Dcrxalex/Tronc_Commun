/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:50:24 by aldecro           #+#    #+#             */
/*   Updated: 2026/04/20 11:11:08 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	handle_conv(char c, va_list *ap);

//print
int	ft_putchar(char c);
int	ft_putstr(char *s);

//helpers
int	help_char(int c);
int	help_perc(void);
int	help_str(char *s);
int	help_int(int n);
int	help_unsigned(unsigned int n);
int	help_hex(unsigned long n, int uppercase);
int	help_pointer(unsigned long n);

#endif
