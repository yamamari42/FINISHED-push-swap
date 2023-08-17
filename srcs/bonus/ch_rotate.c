/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:42:17 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/17 17:10:09 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

void	ch_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = ch_get_tail(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ch_ra(t_node **stack_a)
{
	ch_rotate(stack_a);
	return ;
}

void	ch_rb(t_node **stack_b)
{
	ch_rotate(stack_b);
	return ;
}

void	ch_rr(t_node **stack_a, t_node **stack_b)
{
	ch_rotate(stack_a);
	ch_rotate(stack_b);
	return ;
}
