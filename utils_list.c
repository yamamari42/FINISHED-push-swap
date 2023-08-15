#include "push_swap.h"

/////////// creates a new node /////////////////

t_node	*newnode(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	node_add_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

//t_node	*get_tail(t_node *stack)
//{
//	while (stack && stack->next != NULL)
//		stack = stack->next;
//	return (stack);
//}
//
//t_node	*get_node_before_tail(t_node *stack)
//{
//	while (stack && stack->next && stack->next->next != NULL)
//		stack = stack->next;
//	return (stack);
//}

int	stack_size(t_node *stack)
{
		int	size;

		size = 0;
		if (!stack)
				return (0);
		while (stack != NULL)
		{
				stack = stack->next;
				size++;
		}
		return (size);
}
