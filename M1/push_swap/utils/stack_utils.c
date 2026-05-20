#include "../push_swap.h"

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

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
	{
		ft_lstclear(lst);
		return (-1);
	}
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
	new->prev = temp;
	return (0);
}

t_stack	*ft_lstnew(int value)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->value = value;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
