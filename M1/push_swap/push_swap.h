/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecro <decroixalexandre456@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 11:27:27 by aldecro           #+#    #+#             */
/*   Updated: 2026/05/11 10:58:20 by aldecro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	is_complex;
	int	adaptive;
	int	bench;
}	t_flags;

/* stack utils */
t_stack	*build_stack(char **av);
t_stack	*create_n(long n);
t_stack	*ft_last(t_stack *lst);
void	add_to_bott(t_stack **lst, t_stack *new);
int		stack_size(t_stack *lst);

/* validate */
int		is_valid(char **av);
int		is_dup(char **av);
int		is_sorted(t_stack *lst);

/* operation primitives */
void	swap(t_stack **lst);
void	rotate(t_stack **lst);
void	rev_rotate(t_stack **lst);

/* operations */
void	sa(t_stack **lst);
void	sb(t_stack **lst);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **lst);
void	rb(t_stack **lst);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **lst);
void	rrb(t_stack **lst);
void	rrr(t_stack **a, t_stack **b);

/* sort */
void	simple_sort(t_stack **a, t_stack **b);
void	medium_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
int		find_min_pos(t_stack *lst);
int		find_max_pos(t_stack *lst);
void	sort_b(t_stack **a, t_stack **b);
int		find_best_chunk(t_stack *lst, int threshold, int chunk_size);

/* algo selection */
int		parse_flags(char **av, t_flags *flags);
void	sortit(t_stack **a, t_stack **b, t_flags *flags);

/* utils */
long	ft_atol(char *str);
int		ft_sqrt(int n);
void	set_rank(t_stack *a);
void	free_stack(t_stack *lst);
void	rotate_to_pos(t_stack **a, int pos);

#endif
