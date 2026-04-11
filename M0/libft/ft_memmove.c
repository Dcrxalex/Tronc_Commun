/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 14:09:44 by decro             #+#    #+#             */
/*   Updated: 2026/04/10 14:20:22 by decro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	unsigned char *d;
	const unsigned char *s;

	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!d || !s)
		return (NULL);
	if (d > s)
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
