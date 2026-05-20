#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	rotate_to_pos(t_stack **a, int pos, t_flags **flags)
{
	int size;

	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos--)
			ra(a, flags);
	else
	{
		pos = size - pos;
		while (pos--)
			rra(a, flags);
	}
}