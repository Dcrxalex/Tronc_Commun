/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <ikryvenk@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:41:03 by ikryvenk          #+#    #+#             */
/*   Updated: 2026/05/05 14:43:09 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h> //to delate
# include <stdlib.h>
# include <unistd.h>

typedef struct s_bench
{
	int				bench;
	int				totl_oper;
	int				totl_sa;
	int				totl_sb;
	int				totl_ss;
	int				totl_pa;
	int				totl_pb;
	int				totl_ra;
	int				totl_rb;
	int				totl_rr;
	int				totl_rra;
	int				totl_rrb;
	int				totl_rrr;
}					t_bench;

typedef struct s_flags
{
	int				simple;
	int				medium;
	int				complex;
	float			disorder;
	int             print;
	t_bench			*bench;
}					t_flags;

typedef struct s_stack
{
	int				value;
	int median; // 1 if it at the top of median
	int				position;
	long			cost;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int					main(int argc, char **argv);

// Clear utils
void				ft_error(void);
void				ft_lstclear(t_stack **lst);
void				error_freeargv(char **argv, t_flags *flags);
void				freeargv(char **argv);

// Flags
int					flags_check(t_flags **flags, char *argv);
void				flags_to_zero(t_flags **flags);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// Split
char				**ft_split(char const *str, char c);

// Stack utils
int					stack_size(t_stack *lst);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstnew(int value);

// Utils
int					ft_strlen(char *str);
void				rotate_to_pos(t_stack **a, int pos, t_flags **flags);

// Valid utils
int					is_sorted(t_stack *lst);
int					ft_isdigit(int c);
void				is_validAndFlags(char **av, t_flags **flags);
int					check_same_nbr(t_stack **stack_a);

// Choose Algo
void				sortit(t_stack **a, t_flags **flags);

// Create stack
long				ft_atol(char *str);
void				ft_create_stack(char **argv, t_stack **stack_a, t_flags **flags);
void				ft_sort_create(char **argv, t_stack **stack_a, t_flags **flags);
char				*ft_argvjoin(char **argv);
void				ft_sort_create(char **argv, t_stack **stack_a, t_flags **flags);

// Simple sort
void				sort_three(t_stack **a, t_flags **flags);
int					find_max_pos(t_stack *lst);
int					find_min_pos(t_stack *lst);
void				simple_sort(t_stack **a, t_stack **b, t_flags **flags);

// Operations
void				sa(t_stack **lst, t_flags **flags);
void				sb(t_stack **lst, t_flags **flags);
void				ss(t_stack **a, t_stack **b, t_flags **flags);
void				ra(t_stack **lst, t_flags **flags);
void				rb(t_stack **lst, t_flags **flags);
void				rr(t_stack **a, t_stack **b, t_flags **flags);
void				rra(t_stack **lst, t_flags **flags);
void				rrb(t_stack **lst, t_flags **flags);
void				rrr(t_stack **a, t_stack **b, t_flags **flags);
void				pb(t_stack **a, t_stack **b, t_flags **flags);
void				pa(t_stack **a, t_stack **b, t_flags **flags);

void				swap(t_stack **lst);
void				rotate(t_stack **lst);
void				rev_rotate(t_stack **lst);

int					ft_printf(const char *str, ...);

// Complex sort
void				complex_sort(t_stack **a, t_stack **b, t_flags **flags);
void				calcul_cost(t_stack **from);
void				search_target_a(t_stack **from, t_stack **to);
void				search_target_b(t_stack **from, t_stack **to);
void				calcul_pos(t_stack **stack);
void				search_cheapest(t_stack **stack);
void				turn_a(t_stack **from, t_stack **to, t_flags **flags); 
void				turn_b(t_stack **from, t_stack **to, t_flags **flags);

#endif
