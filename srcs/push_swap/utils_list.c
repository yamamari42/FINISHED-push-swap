/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:42:41 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/17 15:33:37 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/////////// creates a new node /////////////////

t_node	*newnode(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

///////// adds a node to the back /////////////

void	node_add_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

///////// gets stack size /////////////////////

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

////// get lowest index position /////////////

int	get_lowest_index_position(t_node **stack)
{
	t_node	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	find_pos(stack);
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
long long int	ch_upgraded_atoi(const char *n)
{
	int				i;
	long long int	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (n[i] == 32 || (n[i] >= 9 && n[i] <= 13))
		i++;
	if (n[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (n[i] == '+')
		i++;
	while (n[i] == '0')
			i++;
	while (n[i] != '\0' && (n[i] >= '0' && n[i] <= '9'))
	{
		res = res * 10 + (n[i] - '0');
		i++;
	}
	return (res * sign);
}
