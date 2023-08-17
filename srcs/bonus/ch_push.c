/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:42:04 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/17 17:38:51 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

void	ch_push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	ch_pa(t_node **stack_b, t_node **stack_a)
{
	ch_push(stack_b, stack_a);
	return ;
}

void	ch_pb(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_b))
		ch_push(stack_a, stack_b);
	return ;
}
