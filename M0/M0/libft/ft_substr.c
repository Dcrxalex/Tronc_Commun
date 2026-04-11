/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decro <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:37:49 by decro             #+#    #+#             */
/*   Updated: 2026/04/11 15:17:42 by decro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	max_len;
	char	*res;
	size_t	i;

	max_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > max_len)
		return (ft_strdup(""));
	if (len > max_len + start)
		len = max_len + start;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
