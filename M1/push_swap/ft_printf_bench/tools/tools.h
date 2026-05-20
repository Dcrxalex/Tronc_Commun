/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:31:20 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/04/23 14:28:32 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	hashtag;
	int	space;
	int	plus;
}	t_flags;

size_t	ft_strlen(char *str);
char	*ft_itoa(int n);
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_unsitoa(unsigned int n);
int		ft_putnbr_base(unsigned long long nbr, char *base, \
		int type, t_flags *flags);
size_t	ft_type_c(va_list *list);
size_t	ft_type_s(va_list *list);
size_t	ft_type_di(va_list *list, t_flags *flags);
size_t	ft_type_u(va_list *list);

#endif
