/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:16:30 by decro             #+#    #+#             */
/*   Updated: 2026/04/22 17:58:38 by decro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*res;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set) && s1[start])
		start++;
	while (is_set(s1[end], set) && s1[end])
		end--;
	res = ft_substr(s1, start, (end - start + 1));
	return (res);
}
