/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:19:07 by decro             #+#    #+#             */
/*   Updated: 2026/04/28 10:41:22 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*word_dup(const char *s, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while (s[len] != c && s[len])
		len++;
	word = ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **res, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char	**fill_word(char **res, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j++] = word_dup(&s[i], c);
			if (!res[j - 1])
			{
				ft_free(res, j - 1);
				return (NULL);
			}
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	res = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	res = fill_word(res, s, c);
	return (res);
}
