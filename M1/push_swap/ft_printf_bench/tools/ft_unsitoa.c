/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:10:17 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/04/22 15:57:20 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static int	ft_length(unsigned int n)
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

char	*ft_unsitoa(unsigned int n)
{
	int				length;
	char			*fin;
	unsigned int	in;

	in = n;
	length = ft_length(in);
	fin = malloc((sizeof (char)) * (length + 1));
	if (!fin)
		return (NULL);
	fin[length] = '\0';
	while (in > 0)
	{
		fin[--length] = in % 10 + '0';
		in /= 10;
	}
	if (length != 0)
		fin[--length] = '0';
	return (fin);
}
