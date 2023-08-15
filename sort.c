#include "push_swap.h"

//////////// check if already sorted //////////

int	check_if_sorted(t_node **stack_a)
{
		t_node *tmp;

		tmp = *stack_a;

		while (tmp->next)
		{
				if (tmp->content < tmp->next->content)
						tmp = tmp->next;
				else
						return (0);
		}
		return (1);
}

///////////// all sort function //////////////////

int	sort(t_node **stack_a, t_node **stack_b)
{
		int	size;

		size = stack_size(*stack_a);
		if (size == 1)
				return (0);
		else if (size == 2)
		{
				if (check_if_sorted(stack_a) == 0)
						sa(stack_a);
		}
		else if (size == 3)
		{
				if (check_if_sorted(stack_a) == 0)
						do_small_algo(stack_a);
		}
		else if (size > 3)
		{
				if (check_if_sorted(stack_a) == 0)
						do_big_algo(stack_a, stack_b);
		}
		return (0);
}

