/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ch_main_utils3.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: mmardere <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/17 16:04:05 by mmardere	       #+#    #+#	      */
/*   Updated: 2023/08/17 16:05:22 by mmardere         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "bonus_push_swap.h"

//////////////////////////////////

int	ch_stock_args(t_s *s, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			if (ch_split_args(s, argv) == 1)
				return (1);
		}
		else if (argc > 2 && argv[i][j] != '\0')
		{
			s->args = (char **)malloc(argc * sizeof(char *));
			if (!s->args)
				return (1);
			while (argv[i] && argv[i] != NULL)
			s->args[j++] = ft_strdup(argv[i++]);
			s->args[j] = NULL;
			return (1);
		}
		return (0);
	}
	return (-1);
}

//////////////////////////////////

int	ch_stack_size(t_node *stack)
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

//////////////////////////////////

int	ch_check_if_sorted(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

//////////////////////////////////

int	ch_check_double(t_node **stack_a)
{
	t_node	*head;
	t_node	*tmp;

	head = *stack_a;
	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->content == tmp->content)
				return (0);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (1);
}

//////////////////////////////////

int	ch_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}
