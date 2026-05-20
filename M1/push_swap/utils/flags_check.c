#include "../push_swap.h"
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		c;

	i = 0;
	while (((unsigned char)s1[i] != '\0' || (unsigned char)s2[i] != '\0')
		&& i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			c = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (c);
		}
		i++;
	}
	return (0);
}

void	flags_to_zero(t_flags **flags)
{
	(*flags)->simple = 0;
	(*flags)->medium = 0;
	(*flags)->complex = 0;
}

static int	create_bench(t_flags **flags)
{
	t_bench	*bench;

	if ((*flags)->bench != NULL)
		return (7);
	(*flags)->bench = malloc(sizeof(t_bench));
	if (!(*flags)->bench)
		return (-1);
	bench = (*flags)->bench;
	bench->bench = 1;
	bench->totl_oper = 0;
	bench->totl_sa = 0;
	bench->totl_sb = 0;
	bench->totl_ss = 0;
	bench->totl_pa = 0;
	bench->totl_pb = 0;
	bench->totl_ra = 0;
	bench->totl_rb = 0;
	bench->totl_rr = 0;
	bench->totl_rra = 0;
	bench->totl_rrb = 0;
	bench->totl_rrr = 0;
	return (7);
}

int	flags_check(t_flags **flags, char *argv)
{
	if (ft_strncmp(argv, "--bench\0", 8) == 0)
		return (create_bench(flags));
	flags_to_zero(flags);
	if (ft_strncmp(argv, "--simple\0", 9) == 0)
	{
		(*flags)->simple = 1;
		return (8);
	}
	else if (ft_strncmp(argv, "--medium\0", 10) == 0)
	{
		(*flags)->medium = 1;
		return (8);
	}
	else if (ft_strncmp(argv, "--complex\0", 10) == 0)
	{
		(*flags)->complex = 1;
		return (9);
	}
	else if (ft_strncmp(argv, "--adaptive\0", 11) == 0)
		return (10);
	else
		return (1);
}
