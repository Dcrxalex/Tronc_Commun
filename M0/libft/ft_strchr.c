/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:30:28 by decro             #+#    #+#             */
/*   Updated: 2026/04/11 15:18:00 by decro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	ch;

	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (ch == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (ch == s[i])
		return ((char *)&s[i]);
	return (NULL);
}
