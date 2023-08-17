/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:41:40 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/17 15:40:25 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"
#include "push_swap.h"

/////////// string compare ///////////

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/////////// check if move ////////////

int	check_if_move(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0 \
	|| ft_strcmp(line, "ss\n") == 0 || ft_strcmp(line, "ra\n") == 0 \
	|| ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rr\n") == 0 \
	|| ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0 \
	|| ft_strcmp(line, "rrr\n") == 0 || ft_strcmp(line, "pa\n") == 0 \
	|| ft_strcmp(line, "pb\n") == 0)
		return (0);
	else
		return (1);
}

////////// check if sorted ///////////

void	ok_or_ko(t_node **stack_a, int size)
{
	if (ch_check_if_sorted(stack_a) != 1 && ch_stack_size(*stack_a) != size)
	{
		ch_free_stack(stack_a);
		write(1, "KO\n", 3);
		exit (1);
	}
	write(1, "OK\n", 3);
	return ;
}

/////////// checker //////////////////

void	checker(t_node **stack_a, t_node **stack_b)
{
	char	*line;
	int		size;

	size = ch_stack_size(*stack_a);
	line = get_next_line(0);
	while (line && *line != '\0')
	{
		if (check_if_move(line) == 1)
		{
			free(line);
			ch_free_stack(stack_a);
			err();m
			exit (1);
		}
		exec_move(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	ok_or_ko(stack_a, size);
	return ;
}

//////////// main ////////////////////

int	main(int argc, char **argv)
{
	t_s		s;
	t_node	*stack_aa;
	t_node	*stack_bb;

	s.ac = argc;
	stack_bb = NULL;
	s.args = NULL;
	if (ch_stock_args(&s, argc, argv) < 1)
	{
		if (ch_stock_args(&s, argc, argv) == 0)
			err();
		ch_free_args(&s);
		exit (1);
	}
	if (ch_check_if_empty(&s) == 1)
		return (ch_free_args(&s), 1);
	if (ch_check_if_number(&s) == 0)
		return (ch_free_args(&s), err(), 1);
	if (ch_printargs(&s, &stack_aa) == 0)
		return (ch_free_args(&s), ch_free_stack(&stack_aa), err(), 1);
	ch_free_args(&s);
	checker(&stack_aa, &stack_bb);
	ch_free_stack(&stack_aa);
	return (0);
}

