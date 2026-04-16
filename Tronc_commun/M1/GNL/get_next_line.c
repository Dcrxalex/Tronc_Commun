/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 10:14:28 by aldecro           #+#    #+#             */
/*   Updated: 2026/04/15 21:44:51 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_lefto(int fd, char *lefto)
{
	char	*buffer;
	char	*tmp;
	int		bytes_r;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_r = 1;
	while (!ft_strchr(lefto, '\n') && bytes_r > 0)
	{
		bytes_r = read(fd, buffer, BUFFER_SIZE);
		if (bytes_r <= 0)		// return (lefto) ? and not use break?
			break ;
		buffer[bytes_r] = '\0';	//you return string by string
		tmp = lefto;
		lefto = ft_strjoin(lefto, buffer);
		free(tmp);
	}
	free(buffer);
	return (lefto);
}

char	*extract_line(char *lefto)
{
	char	*res;
	int		i;

	i = 0;
	while (lefto[i] != '\n' && lefto[i])
		i++;
	if (lefto[i] == '\n')
		i++;
	res = ft_substr(lefto, 0, i);
	return (res);
}

char	*trim_lefto(char *lefto)
{
	char	*res;
	char	*line;

	line = ft_strchr(lefto, '\n');
	if (!line)
		return (NULL);
	res = ft_substr(lefto, line - lefto + 1, ft_strlen(lefto));
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*lefto;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lefto = fill_lefto(fd, lefto);
	if (!lefto)
		return (NULL);
	line = extract_line(lefto);
	tmp = lefto;
	lefto = trim_lefto(lefto);
	free(tmp);
	return (line);
}
