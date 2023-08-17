/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:42:11 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/15 20:47:37 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

t_node	*ch_get_stack_before_bottom(t_node *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ch_rev_rotate(t_node **stack)
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

void	ch_rra(t_node **stack_a)
{
	ch_rev_rotate(stack_a);
	return ;
}

void	ch_rrb(t_node **stack_b)
{
	ch_rev_rotate(stack_b);
	return ;
}

void	ch_rrr(t_node **stack_a, t_node **stack_b)
{
	ch_rev_rotate(stack_a);
	ch_rev_rotate(stack_b);
	return ;
}

