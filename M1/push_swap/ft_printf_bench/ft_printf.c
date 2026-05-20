/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:40:40 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/04/24 13:28:41 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_type(char c, va_list *list, t_flags *flags)
{
	if (c == 'c')
		return (ft_type_c(list));
	else if (c == 's')
		return (ft_type_s(list));
	else if (c == 'd' || c == 'i')
		return (ft_type_di(list, flags));
	else if (c == 'u')
		return (ft_type_u(list));
	else if (c == '%')
	{
		ft_putchar_fd(c, 2);
		return (1);
	}
	else if (c == 'X')
		return (ft_putnbr_base((unsigned long long)va_arg(*list, unsigned int), \
											"0123456789ABCDEF", 'X', flags));
	else if (c == 'x')
		return (ft_putnbr_base((unsigned long long)va_arg(*list, unsigned int), \
											"0123456789abcdef", 'x', flags));
	else if (c == 'p')
		return (ft_putnbr_base((unsigned long long)va_arg(*list, void *), \
											"0123456789abcdef", 'p', flags));
	else
		return (-1);
}

static int	ft_flags(int i, char *str, t_flags *flags)
{
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
	while (str[i] != 'c' && str[i] != 's' && str[i] != 'd' && str[i] != 'i' && \
	str[i] != '\0' && str[i] != 'u' && str[i] != '%' && str[i] != 'X' && \
	str[i] != 'x' && str[i] != 'p')
	{
		if (str[i] == ' ')
			flags->space = 1;
		else if (str[i] == '#')
			flags->hashtag = 1;
		else if (str[i] == '+')
			flags->plus = 1;
		else
			return (0);
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list			list;
	t_flags			flags;
	int				i;
	int				len;
	int				temp;

	len = 0;
	i = -1;
	va_start (list, str);
	while (str[++i])
	{
		if (str[i++] == '%')
		{
			i = ft_flags(i, (char *)str, &flags);
			temp = (int)ft_type(str[i], &list, &flags);
			if (temp < 0 || i == 0)
				return (-1);
			len += temp;
		}
		else
			len += ft_putchar_fd(str[--i], 2);
	}
	va_end (list);
	return (len);
}
/*
#include <limits.h>
int	main(void)
{
	ft_printf("C\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %c", 'i'));
    printf(" Return: %d\n\n", printf("Real:%c", 'i'));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %c", 'U'));
    printf(" Return: %d\n\n", printf("Real:%c", 'U'));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %c", NULL));
    printf(" Return: %d\n\n", printf("Real:%c", NULL));
    
    ft_printf("S\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %s", "Tes\0te"));
    printf(" Return: %d\n\n", printf("Real:%s", "Tes\0te"));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %s", "Test"));
    printf(" Return: %d\n\n", printf("Real:%s", "Test"));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %s", NULL));
    printf(" Return: %d\n\n", printf("Real:%s", NULL));
    
    ft_printf("D and I\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %d", 0));
    printf(" Return: %d\n\n", printf("Real:%d", 0));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %d", LONG_MIN));
    printf(" Return: %d\n\n", printf("Real:%d", LONG_MIN));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %i", LONG_MAX));
    printf(" Return: %d\n\n", printf("Real:%i", LONG_MAX));
    
    ft_printf("U\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %u", 0));
    printf(" Return: %d\n\n", printf("Real:%u", 0));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %u", LONG_MIN));
    printf(" Return: %d\n\n", printf("Real:%u", LONG_MIN));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %u", LONG_MAX));
    printf(" Return: %d\n\n", printf("Real:%u", LONG_MAX));
    
    ft_printf("%\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %%"));
    printf(" Return: %d\n\n", printf("Real:%%"));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %"));
    printf(" Return: %d\n\n", printf("Real:%"));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %%%%"));
    printf(" Return: %d\n\n", printf("Real:%%%%"));
    
    ft_printf("x\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %x", 0));
    printf(" Return: %d\n\n", printf("Real:%x", 0));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %x", LONG_MIN));
    printf(" Return: %d\n\n", printf("Real:%x", LONG_MIN));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %x", LONG_MAX));
    printf(" Return: %d\n\n", printf("Real:%x", LONG_MAX));
    
    ft_printf("X\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %X", 0));
    printf(" Return: %d\n\n", printf("Real:%X", 0));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %X", LONG_MIN));
    printf(" Return: %d\n\n", printf("Real:%X", LONG_MIN));

    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %X", LONG_MAX));
    printf(" Return: %d\n\n", printf("Real:%X", LONG_MAX));
    
    ft_printf("P\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %p", 0));
    printf(" Return: %d\n\n", printf("Real:%p", 0));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %p", LONG_MIN));
    printf(" Return: %d\n\n", printf("Real:%p", LONG_MIN));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %p", LONG_MAX));
    printf(" Return: %d\n\n", printf("Real:%p", LONG_MAX));
    
    ft_printf("--- Bonus part:\n\n");
	
	ft_printf("Hash (#)\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %#x", 0));
    printf(" Return: %d\n\n", printf("Real:%#x", 0));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %#x", -12));
    printf(" Return: %d\n\n", printf("Real:%#x", -12));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %#x", INT_MAX));
    printf(" Return: %d\n\n", printf("Real:%#x", INT_MAX));
    
    ft_printf("Test4\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %#x", LONG_MIN));
    printf(" Return: %d\n\n", printf("Real:%#x", LONG_MIN));
    
    ft_printf("Test5\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %#X", 0));
    printf(" Return: %d\n\n", printf("Real:%#X", 0));
    
    ft_printf("Test6\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %#X", -12));
    printf(" Return: %d\n\n", printf("Real:%#X", -12));
    
    ft_printf("Test7\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %#X", INT_MAX));
    printf(" Return: %d\n\n", printf("Real:%#X", INT_MAX));

    ft_printf("Test8\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %#X", LONG_MIN));
    printf(" Return: %d\n\n", printf("Real:%#X", LONG_MIN));
    
    ft_printf("\n\nSpace ( )\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  % s", ""));
    printf(" Return: %d\n\n", printf("Real:% s", ""));
    
    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  % d", 0));
    printf(" Return: %d\n\n", printf("Real:% d", 0));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  % d", INT_MIN));
    printf(" Return: %d\n\n", printf("Real:% d", INT_MIN));
    
    ft_printf("Test4\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  % i", -101));
    printf(" Return: %d\n\n", printf("Real:% i", -101));
    
    ft_printf("\n\nPlus (+)\n");
    
    ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+d", 0));
    printf(" Return: %d\n\n", printf("Real:%+d", 0));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+d", LONG_MIN));
    printf(" Return: %d\n\n", printf("Real:%+d", LONG_MIN));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+i", -101));
    printf(" Return: %d\n\n", printf("Real:%+i", -101));

    ft_printf("Test4\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+s", ""));
    printf(" Return: %d\n\n", printf("Real:%+s", ""));
    
    ft_printf("Test5\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+x", 11));
    printf(" Return: %d\n\n", printf("Real:%+x", 11));
    
    ft_printf("\n\nMIX\n");
    
	ft_printf("Test1\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+ #d", 0));
    printf(" Return: %d\n\n", printf("Real:%+ #d", 0));

    ft_printf("Test2\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+     d", LONG_MIN));
    printf(" Return: %d\n\n", printf("Real:%+      d", LONG_MIN));
    
    ft_printf("Test3\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+  #+  i", -101));
    printf(" Return: %d\n\n", printf("Real:%+  #+  i", -101));

    ft_printf("Test4\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+#s", ""));
    printf(" Return: %d\n\n", printf("Real:%+#s", ""));
    
    ft_printf("Test5\n");
    ft_printf(" Return: %d\n", ft_printf("MY:  %+   ####x", 11));
    printf(" Return: %d\n\n", printf("Real:%+   ####x", 11));
    
    return (0);
}*/
