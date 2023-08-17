/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:41:17 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/15 21:00:35 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///////// counts No of moves for the 2nd half of the stack B /////////

int	get_rra_count(t_node *tmp2)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = tmp2;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/////// counts No of moves to put each element to the top of stack /////

void	get_to_top_of_b(t_node **stack_b)
{
	int		size;
	t_node	*tmp;

	size = stack_size(*stack_b);
	tmp = *stack_b;
	if (size == 1)
		tmp->to_top_b = 0;
	else if (size == 2)
	{
		tmp->to_top_b = 0;
		tmp->next->to_top_b = 1;
	}
	else if (size >= 3)
	{
		while (tmp && tmp->pos <= size / 2 + 1)
		{
				tmp->to_top_b = tmp->pos - 1;
				tmp = tmp->next;
		}
		while (tmp)
		{
				tmp->to_top_b = get_rra_count(tmp);
				tmp = tmp->next;
		}
	}
}

///////////////// pushes all except 3 last //////////////////////

void	pb_leave_three(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
	if (check_if_sorted(stack_a) == 0)
			do_small_algo(stack_a);
}

/////////////////////////////////////////////////////////////////////

void	do_big_algo(t_node **stack_a, t_node **stack_b)
{
	pb_leave_three(stack_a, stack_b);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!check_if_sorted(stack_a))
		shift_stack(stack_a);
}
