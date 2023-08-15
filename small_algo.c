
#include "push_swap.h"

void assign_index(t_node **stack_a)
{
	t_node *tmp;
	int index = 1;
	// int position;
	int lowest_i;
	int	i = 0;

	while (index < stack_size(*stack_a) + 1)
	{
		i = 0;
		tmp = *stack_a;
		lowest_i = lowest_index(stack_a);
		while (i < lowest_i)
		{
			tmp = tmp->next;
			i++;
		}
		tmp->index = index;
		index++;
	}
}

void	do_small_algo(t_node **stack_a)
{
		int	highest;

		highest = highest_index(*stack_a);
		if ((*stack_a)->index == highest)
				ra(stack_a);
		else if ((*stack_a)->next->index == highest)
				rra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
				sa(stack_a);
}
