/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ch_main_utils.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: mmardere <mmardere@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/17 14:54:31 by mmardere	       #+#    #+#	      */
/*   Updated: 2023/08/17 16:10:04 by mmardere         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "bonus_push_swap.h"

/////////////////////////////////////////

t_node	*ch_newnode(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/////////////////////////////////////////

void	ch_node_add_back(t_node **lst, t_node *new)
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

/////////////////////////////////////////

t_node	*ch_get_node_before_tail(t_node *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/////////////////////////////////////////

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
