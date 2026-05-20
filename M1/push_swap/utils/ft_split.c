/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:19:44 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/04/29 14:14:42 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_word_copy(char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((sizeof(char)) * (end - start + 1));
	if (!(word))
		return (NULL);
	while (start != end)
	{
		word[i++] = str[start];
		start++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_words(char *str, char charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] && str[i] != charset)
		{
			word++;
			while (str[i] && str[i] != charset)
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char	**ft_error_split(char **split, int n)
{
	while (n >= 0)
		free(split[n--]);
	free(split);
	return (NULL);
}

static char	**ft_help(char **split, int n)
{
	split[n] = NULL;
	return (split);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		i;
	int		start;
	int		n;

	n = 0;
	i = 0;
	split = malloc(sizeof(char *) * (ft_words((char *)str, c) + 1));
	if (!str || !(split))
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		if (start < i)
		{
			split[n++] = ft_word_copy((char *)str, start, i);
			if (!(split[n - 1]))
				return (ft_error_split(split, n - 2));
		}
	}
	return (ft_help(split, n));
}
