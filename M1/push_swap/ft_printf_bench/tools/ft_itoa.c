/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:50:31 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/04/22 15:56:46 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static int	ft_length(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			length;
	char		*fin;
	long		in;

	in = n;
	if (n < 0)
		in = -in;
	length = ft_length(in);
	if (n < 0)
		length += 1;
	fin = malloc((sizeof (char)) * (length + 1));
	if (!fin)
		return (NULL);
	fin[length] = '\0';
	while (in > 0)
	{
		fin[--length] = in % 10 + '0';
		in /= 10;
	}
	if (n < 0)
		fin[--length] = '-';
	if (length != 0)
		fin[--length] = '0';
	return (fin);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(-123));
	return (0);
}*/
