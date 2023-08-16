/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:41:49 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/16 19:21:24 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//////////// upgraded + INT_MIN INT_MAX ////////////////////////

long long int	upgraded_atoi(const char *n)
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

////////// check if INT_MIN or INT_MAX //////////////

int	check_if_int_overflow(const char *n, t_s *s)
{
	long long int	res;

	res = upgraded_atoi(n);
	if (res >= INT_MIN && res <= INT_MAX)
		return (res);
	else
	{
		err();
		free_args(s);
		exit (1);
	}
}

///////////////// applying atoi /////////////////////

t_node	*do_atoi(t_s *s)
{
	t_node	*stack;
	t_node	*tmp;
	int		i;

	stack = NULL;
	i = 0;
	while (s->args[i])
	{
		tmp = newnode(check_if_int_overflow(s->args[i], s));
		tmp->index = 0;
		node_add_back(&stack, tmp);
		i++;
	}
	return (stack);
}


/////////////// checks for number doubles /////////////

int	check_double(t_node **stack_a)
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

//////////////////////////////////////////////

int	printargs(t_s *s, t_node **stack_a)
{
	*stack_a = do_atoi(s);

	if (check_double(stack_a) == 0)
		return (0);
	return (1);
}
