/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:34:55 by decro             #+#    #+#             */
/*   Updated: 2026/04/22 18:03:27 by decro            ###   ########.fr       */
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
	char	*res;

	nb = n;
	res = ft_calloc(itoa_len(nb) + 1, sizeof(char));
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
	i = itoa_len(nb) - 1;
	while (nb != 0)
	{
		res[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
