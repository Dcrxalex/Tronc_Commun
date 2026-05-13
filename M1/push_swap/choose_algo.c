#include "push_swap.h"

void	sortit(t_stack **a, t_flags **flags)
{
	t_stack	*b;

	b = NULL;
	(void)flags;
	simple_sort(a, &b);
}
