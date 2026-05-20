/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:29:01 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/04/23 14:28:59 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

size_t	ft_type_c(va_list *list)
{
	ft_putchar_fd(va_arg(*list, int), 2);
	return (1);
}

size_t	ft_type_s(va_list *list)
{
	void	*temp;

	temp = va_arg(*list, char *);
	if (temp == NULL)
	{
		ft_putstr_fd(temp, 2);
		return (6);
	}
	ft_putstr_fd(temp, 2);
	return (ft_strlen(temp));
}

size_t	ft_type_u(va_list *list)
{
	void	*temp;
	size_t	len;

	temp = ft_unsitoa(va_arg(*list, unsigned int));
	if (temp == NULL)
		return (-1);
	len = ft_strlen(temp);
	ft_putstr_fd(temp, 2);
	free(temp);
	return (len);
}

size_t	ft_type_di(va_list *list, t_flags *flags)
{
	void	*temp;
	size_t	len;
	int		nbr;

	nbr = va_arg(*list, int);
	temp = ft_itoa(nbr);
	if (temp == NULL)
		return (-1);
	len = ft_strlen(temp);
	if (nbr >= 0 && flags->plus == 1)
	{
		len++;
		ft_putchar_fd('+', 2);
	}
	else if (nbr >= 0 && flags->space == 1)
	{
		len++;
		ft_putchar_fd(' ', 1);
	}
	ft_putstr_fd(temp, 2);
	free(temp);
	return (len);
}
