/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:32:51 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/04/29 14:26:18 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check(char *buffer, char **line)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			return (ft_check_help(buffer, line, i));
		}
		i++;
	}
	if (i == 0)
		return (2);
	if (i > 0)
		return (3);
	return (0);
}

static int	ft_stock(char *buffer, char **line)
{
	int		i;
	int		j;
	char	*swap;
	int		k;

	i = 0;
	j = 0;
	while (buffer[j] != '\n' && buffer[j])
		j++;
	if (*line != NULL)
	{
		i = ft_strlen(*line) + 1;
		k = ft_check_help(*line, &swap, ft_strlen(*line) - 1);
		if (k == -1)
			return (-1);
		free(*line);
		*line = ft_stock_help(buffer, swap, j, i);
		free(swap);
		return (ft_specify_check(line));
	}
	k = ft_check_help(buffer, line, j - 1);
	if (k == -1)
		return (k);
	return (ft_specify_check(line));
}

static int	get_next_line_help(int fd, char *buffer, char **line, int t)
{
	int	readt;

	readt = read(fd, buffer, BUFFER_SIZE);
	if (readt > 0)
	{
		buffer[readt] = '\0';
		if (t == 0)
			return (ft_check(buffer, line));
		else
			return (ft_stock(buffer, line));
	}
	else if (readt == 0)
		return (1);
	else
	{
		if (t == 1)
			free(line);
		return (-1);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			check;
	int			t;

	line = NULL;
	check = ft_check(buffer, &line);
	t = 0;
	while (1)
	{
		if (check == 1)
			return (line);
		else if (check == 2)
			check = get_next_line_help(fd, buffer, &line, t);
		else if (check == 3)
		{
			check = ft_stock(buffer, &line);
			t = 1;
		}
		else
			return (NULL);
	}
}

//#include <errno.h>
//#include <stdio.h>
//int	main(void)
//{
//	int	fd;

//	fd = open("test.txt", O_RDONLY);
//	if (fd == -1)
//	{
//		perror("");
//		return (-1);
//	}
//	for (int i = 0; i < 8; i++)
//		printf("%s", get_next_line(fd));
//	if (close(fd) < 0)
//	{
//		perror("");
//		return (-1);
//	}
//	return (0);
//}
