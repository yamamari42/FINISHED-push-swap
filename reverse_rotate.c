#include "push_swap.h"

// Brings the bottom element of a stack to the top.


t_node	*get_stack_bottom(t_node *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_stack_before_bottom:
*	Returns the second to last element of the stack.
*/
t_node	*get_stack_before_bottom(t_node *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	rev_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tail;
	t_node	*before_tail;

	tail = get_tail(*stack);
	before_tail = get_node_before_tail(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	rra(t_node **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
