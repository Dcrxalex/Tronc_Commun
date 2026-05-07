/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:11:32 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/06 23:09:38 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sorted(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_valid(char **av)
{
	int		i;
	int		j;
	long	n;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		if (!av[i][j])
		{
			write(2, "Error\n", 6);
			return (0);
		}
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		n = ft_atol(av[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_dup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;

	}
}
