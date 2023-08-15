/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:42:36 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/15 20:44:59 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	swap(t_node *node)
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

void	sa(t_node **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}

