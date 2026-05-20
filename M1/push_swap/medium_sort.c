#include "push_swap.h"

int compute_cost(int pos, int size)
{
    if (pos <= size / 2)
        return (pos);
    return (pos - size);
}

int find_best_chunk(t_stack *lst, int threshold, int chunk_size)
{
    int i;
    int best_pos;
    int best_cost;
    int cost;
    int size;

    i = 0;
    best_pos = -1;
    size = stack_size(lst);
    best_cost = size;
    while (lst)
    {
        if (lst->rank >= threshold - size && lst->rank < threshold)
        {
            cost = compute_cost(i, size);
            if (cost < best_cost)
            {
                best_cost = cost;
                best_pos = i;
            }
        }
        i++;
        lst = lst->next;
    }
    return (best_pos);
}

static void    push_chunk(t_stack **a, t_stack **b, int threshold, int chunk_size)
{
    int pos;

    pos = find_best_chunk(*a, threshold, chunk_size);
    while (pos != -1)
    {
        rotate_to_pos(a, pos);
        pb(a, b);
        pos = find_best_chunk(*a, threshold, chunk_size);
    }
}

void    medium_sort(t_stack **a, t_stack **b)
{
    int chunk_size;
    int threshold;

    set_rank(*a);
    chunk_size = ft_sqrt(stack_size(*a));
    threshold = chunk_size;
    while (*a)
    {
        push_chunk(a, b, threshold, chunk_size);
        threshold += chunk_size;
    }
    while (*b)
        sort_b(a, b);
}