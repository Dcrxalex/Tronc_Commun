/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:44:06 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/06 16:45:07 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*build_stack(char **av, int start)
{
	t_stack *a;
	t_stack *new_n;
	int		i;

	a = NULL;
	i = start;
	while (av[i])
	{
		new_n = create_n(ft_atol(av[i]));
		if (!new_n)
			return (NULL);
		add_to_bott(&a, new_n);
		i++;
	}
	return (a);
}

t_stack	*create_n(long n)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = (int)n;
	new->next = NULL;
	return (new);
}
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	add_to_bott(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

int	stack_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
