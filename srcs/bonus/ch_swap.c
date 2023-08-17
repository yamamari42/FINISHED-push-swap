/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:42:36 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/17 14:34:01 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bonus_push_swap.h"

void	ch_swap(t_node *node)
{
	int	tmp;

	if (node == NULL || node->next == NULL)
		return ;
	tmp = node->content;
	node->content = node->next->content;
	node->next->content = tmp;
	tmp = node->index;
	node->index = node->next->index;
	node->next->index = tmp;
}

void	ch_sa(t_node **stack_a)
{
	ch_swap(*stack_a);
	return ;
}

void	ch_sb(t_node **stack_b)
{
	ch_swap(*stack_b);
	return ;
}

void	ch_ss(t_node **stack_a, t_node **stack_b)
{
	ch_sa(stack_a);
	ch_sb(stack_b);
	return ;
}

