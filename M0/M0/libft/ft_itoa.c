/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:34:55 by decro             #+#    #+#             */
/*   Updated: 2026/04/09 18:42:14 by decro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	itoa_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	int		len;
	char	*res;

	nb = n;
	len = itoa_len(nb);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (nb == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	i = len - 1;
	while (nb != 0)
	{
		res[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
