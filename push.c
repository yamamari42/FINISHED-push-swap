
#include "push_swap.h"
void	push(t_node **src, t_node **dest)
{
		t_node	*tmp;

		if (*src == NULL)
				return ;
		tmp = (*src)->next;
		(*src)->next = *dest;
		*dest = *src;
		*src = tmp;
}

void	pa(t_node **stack_b, t_node **stack_a)
{
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
}
