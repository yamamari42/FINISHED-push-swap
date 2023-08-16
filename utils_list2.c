/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:42:48 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/16 17:58:44 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//////// get node with highest index ///////////

int	highest_index(t_node *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
				index = stack->index;
		stack = stack->next;
	}
	return (index);

}

/////// get node with lowest index ////////////

int	lowest_index(t_node **stack_a)
{
	int		lowest;
	t_node	*tmp;
	int		position;
	int		index;

	position = 0;
	index = 0;
	tmp = *stack_a;
	lowest = INT_MAX;
	while (tmp)
	{
		if (tmp->content < lowest && !tmp->index)
		{
			lowest = tmp->content;
			position = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (position);
}

///////// get last node /////////////////////////

t_node	*get_tail(t_node *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

//////// get the node before the last one ////////

t_node	*get_node_before_tail(t_node *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

//////// finds position of element in  the current stack //////

void	find_pos(t_node **stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
