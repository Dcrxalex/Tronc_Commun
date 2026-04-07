/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecroi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:24:16 by aldecroi          #+#    #+#             */
/*   Updated: 2026/04/07 11:35:54 by aldecroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void		*content;
	struct s_list	*next;
}	t_list;

//char
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);

//strings
size_t	ft_strlen(const char *str);
size_t	ft_strlpy(char *dst, const char *src, size_t d_size);
size_t	ft_strlcat(char *dst, const char *src, size_t d_size);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);


//file descriptor

//memory
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

//numbers
int	ft_atoi(const char *str);

#endif
