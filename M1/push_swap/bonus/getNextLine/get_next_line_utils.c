/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:46:06 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/04/28 19:47:34 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_help(char *buffer, char **line, int i)
{
	int	j;

	*line = malloc(sizeof(char) * (i + 2));
	if (!*line)
		return (-1);
	j = 0;
	while (j <= i)
	{
		(*line)[j] = buffer[j];
		j++;
	}
	(*line)[j] = '\0';
	j = 0;
	i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
	return (1);
}

int	ft_specify_check(char **line)
{
	int	i;

	if (*line == NULL)
		return (-1);
	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
			return (1);
		i++;
	}
	return (2);
}

char	*ft_stock_help(char *buffer, char *swap, int j, int i)
{
	int		k;
	char	*line;

	line = NULL;
	k = 0;
	if (buffer[j] == '\n')
		line = malloc(sizeof(char) * (j + i + 2));
	else
		line = malloc(sizeof(char) * (j + i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (swap[i])
	{
		(line)[i] = swap[i];
		i++;
	}
	while (k <= j && buffer[k] != '\0')
		(line)[i++] = buffer[k++];
	(line)[i] = '\0';
	i = 0;
	while (buffer[k])
		buffer[i++] = buffer[k++];
	buffer[i] = '\0';
	return (line);
}
