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


//////// pushes all except 3 to stack B, small down, big on top ///////

void	pb_leave_three(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	size;
	int	mid;

	i = 0;
	size = stack_size(*stack_a);
	mid = size / 2;
	while (size > 3)
	{
		pb(stack_a, stack_b);
		if ((*stack_b)->index <= mid && stack_size(*stack_b) > 1)
			ra(stack_b);
		size--;
	}
	do_small_algo(stack_a);
	return ;
}

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

////////////////////////////////////////////////////////////////////

static int	get_target(t_node **a, int b_idx,
								int target_idx, int target_pos)
{
	t_node	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

//////////////////////////////////////////////////////

void	get_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

////////////// get target pos in stack A ////////////////////////////

void	get_target_position(t_node **a, t_node **b)
{
	t_node	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	find_pos(a);
	find_pos(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

/////////////////

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

///////////////// do cheapest move /////////////////////////////////

void	do_cheapest_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

static void	get_position(t_node **stack)
{
	t_node	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
int	get_lowest_index_position(t_node **stack)
{
	t_node	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static void	shift_stack(t_node **stack_a)
{
	int	lowest_pos;
	int	size;

	size = stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}



////////////////////////////////////////////////////////////////////

static void	push_all_save_three(t_node **stack_a, t_node **stack_b)
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
}


void	tiny_sort(t_node **stack)
{
	int		highest;

	if (check_if_sorted(stack))
		return ;
	highest = highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

/////////////////////////////////////////////////////////////////////

void	do_big_algo(t_node **stack_a, t_node **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!check_if_sorted(stack_a))
		shift_stack(stack_a);
}
