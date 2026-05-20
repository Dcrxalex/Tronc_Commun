#include "push_swap.h"

void	copute_disorder(t_stack *a, t_flags **flags)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*next;

	mistakes = 0;
	total_pairs = 0;
	next = NULL;
	if (a->next != NULL)
		next = a->next;
	while (next)
	{
		total_pairs += 1;
		if (a->value > next->value)
			mistakes += 1;
		a = a->next;
		next = next->next;
	}
	if (total_pairs == 0)
		(*flags)->disorder = 0;
	else
		(*flags)->disorder = mistakes / total_pairs;
}

void	disorder_print(float disorder)
{
	int	temp;

	temp = (int)disorder;
	ft_printf("%d", temp);
	disorder -= (float)temp;
	disorder *= 100;
	temp = (int)disorder;
	ft_printf(".%d%%\n", temp);
}

void	bench_print(t_bench *bench, t_flags *flags)
{
	ft_printf("[bench] disorder: ");
	disorder_print(flags->disorder * 100);
	if (flags->simple == 1)
		write(2, "[bench] strategy:  Simple / O(n2)\n", 34);
	else if (flags->medium == 1)
		write(2, "[bench] strategy:  Medium / O(n√n)\n", 35);
	else if (flags->complex == 1)
		write(2, "[bench] strategy:  Complex /  O(n log n)\n", 41);
	bench->totl_oper = bench->totl_sa + bench->totl_sb + bench->totl_ss
		+ bench->totl_pa + bench->totl_pb + bench->totl_ra + bench->totl_rb
		+ bench->totl_rr + bench->totl_rra + bench->totl_rrb + bench->totl_rrr;
	ft_printf("[bench] total_ops: %d\n", bench->totl_oper);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d \n[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", bench->totl_sa,
		bench->totl_sb, bench->totl_ss, bench->totl_pa, bench->totl_pb,\
		bench->totl_ra, bench->totl_rb, bench->totl_rr, bench->totl_rra,\
		bench->totl_rrb, bench->totl_rrr);
}

//void	display_stack(t_stack *a) // to delete
//{
//	while (a)
//	{
//		printf("%d\n", a->value);
//		a = a->next;
//	}
//}

void	sortit(t_stack **a, t_flags **flags) //We need to improve this function add medium and complex mode, do bench mode properly for all mode. specially complex mode.
{
	t_stack	*b;

	copute_disorder(*a, flags);
	b = NULL;
	if (is_sorted(*a) == 1)
		return ;
	if ((*flags)->simple == 1)
		simple_sort(a, &b, flags);
	else if ((*flags)->complex == 1)
		complex_sort(a, &b, flags);
	else if ((*flags)->disorder < 0.2)
	{
		(*flags)->simple = 1;
		simple_sort(a, &b, flags);
	}
	else if ((*flags)->disorder >= 0.5)
	{
		(*flags)->complex = 1;
		complex_sort(a, &b, flags);
	}
	else
		complex_sort(a, &b, flags);
	if ((*flags)->bench != NULL)
		bench_print((*flags)->bench, *flags);
	//display_stack(*a); // to delete
}
