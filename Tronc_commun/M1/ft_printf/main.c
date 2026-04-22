#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ft_ret;
    int printf_ret;

// INT_MIN
ft_ret = ft_printf("INT_MIN: %d\n", (int)-2147483648);
printf_ret = printf("INT_MIN: %d\n", (int)-2147483648);
printf("ft: %d | pf: %d\n\n", ft_ret, printf_ret);

// null string
ft_ret = ft_printf("null string: %s\n", (char *)NULL);
printf("ft: %d | pf: %d\n\n", ft_ret, 20);

// literal percent
ft_ret = ft_printf("percent: %%\n");
printf_ret = printf("percent: %%\n");
printf("ft: %d | pf: %d\n\n", ft_ret, printf_ret);

// hex lowercase
ft_ret = ft_printf("hex: %x\n", 255);
printf_ret = printf("hex: %x\n", 255);
printf("ft: %d | pf: %d\n\n", ft_ret, printf_ret);

// hex uppercase
ft_ret = ft_printf("HEX: %X\n", 255);
printf_ret = printf("HEX: %X\n", 255);
printf("ft: %d | pf: %d\n\n", ft_ret, printf_ret);

// unsigned -1
ft_ret = ft_printf("unsigned: %u\n", -1);
printf_ret = printf("unsigned: %u\n", -1);
printf("ft: %d | pf: %d\n\n", ft_ret, printf_ret);

// pointer
int x = 42;
ft_ret = ft_printf("pointer: %p\n", &x);
printf_ret = printf("pointer: %p\n", &x);
printf("ft: %d | pf: %d\n\n", ft_ret, printf_ret);
}
