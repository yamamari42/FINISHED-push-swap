/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ch_main_utils4.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: mmardere <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/17 16:06:48 by mmardere	       #+#    #+#	      */
/*   Updated: 2023/08/17 16:08:48 by mmardere         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "bonus_push_swap.h"

/////////////////////////////////////

void	ch_free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/////////////////////////////////////

t_node	*ch_do_atoi(t_s *s)
{
	t_node	*stack;
	t_node	*tmp;
	int		i;

	stack = NULL;
	i = 0;
	while (s->args[i])
	{
		tmp = ch_newnode(ch_check_if_int_overflow(s->args[i], s));
		tmp->index = 0;
		ch_node_add_back(&stack, tmp);
		i++;
	}
	return (stack);
}

/////////////////////////////////////

int	ch_split_args(t_s *s, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s->args = ft_split(argv[1], ' ');
	if (!s->args)
	{
		err();
		return (0);
	}
	if (s->args[i] == NULL)
		return (1);
	while (s->args[i])
	{
		while (s->args[i][j])
			j++;
		j = 0;
		i++;
	}
	return (1);
}

/////////////////////////////////////

t_node	*ch_get_tail(t_node *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/////////////////////////////////////

int	ch_check_if_int_overflow(const char *n, t_s *s)
{
	long long int	res;

	res = ch_upgraded_atoi(n);
	if (res >= INT_MIN && res <= INT_MAX)
		return (res);
	else
	{
		err();
		ch_free_args(s);
		exit (1);
	}
}
