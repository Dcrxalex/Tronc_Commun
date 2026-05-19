#include "push_swap.h"

long	ft_atol(char *str)
{
	long	n;
	int		i;
	int		sign;

	n = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * sign);
}

void	ft_create_stack(char **argv, t_stack **stack_a, t_flags **flags)
{
	int		i;
	long	nbr;

	i = 0;
	is_validAndFlags(argv, flags);
	while (argv[i])
	{
		if (argv[i][1] != '-')
		{
			nbr = ft_atol(argv[i]);
			if (nbr > 2147483647 || nbr < -2147483648)
				error_freeargv(argv);
			if (ft_lstadd_back(stack_a, ft_lstnew((int)nbr)) == -1)
				error_freeargv(argv);
		}
		i++;
	}
	if (check_same_nbr(stack_a) == -1)
		error_freeargv(argv);
	freeargv(argv);
}

char	*ft_argvjoin(char **argv)
{
	char	*join;
	int		i;
	int		length;
	int		m;
	int		k;

	i = 0;
	length = 0;
	while (argv[i])
		length += ft_strlen(argv[i++]) + 1;
	join = malloc((sizeof(char)) * (length + 1));
	if (!join)
		ft_error();
	i = 0;
	m = 0;
	while (i < length)
	{
		k = 0;
		while (argv[m][k])
			join[i++] = argv[m][k++];
		join[i++] = ' ';
		m++;
	}
	join[i] = '\0';
	return (join);
}

void	ft_sort_create(char **argv, t_stack **stack_a, t_flags **flags)
{
	char	*input;
	char	**input_divised;

	input = ft_argvjoin(argv);
	input_divised = ft_split(input, ' ');
	free(input);
	if (input_divised == NULL)
		ft_error();
	ft_create_stack(input_divised, stack_a, flags);
}
