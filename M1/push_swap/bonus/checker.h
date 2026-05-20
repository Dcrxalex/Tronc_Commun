#ifndef CHECKER_H
# define CHECKER_H

int     checker_s_oper(t_stack **a, t_stack **b, t_flags **flags, char *command);
int     checker_r_oper(t_stack **a, t_stack **b, t_flags **flags, char *command);
int     checker_rr_oper(t_stack **a, t_stack **b, t_flags **flags, char *command);
int     checker_push_oper(t_stack **a, t_stack **b, t_flags **flags, char *command);

void	ft_checker_error(t_stack **a, t_stack **b, char *command, t_flags **flags);

char			*get_next_line(int fd);

#endif