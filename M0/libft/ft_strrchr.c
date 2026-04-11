/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:33:20 by decro             #+#    #+#             */
/*   Updated: 2026/04/09 10:36:32 by decro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*res;
	int	i;

	i = 0;
	ch = (char)c;
	res = NULL;
	while (s[i])
	{
		if (s[i] == ch)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == ch)
		res = (char *)&s[i];
	return (res);
}
