/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:41:40 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/15 21:10:21 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	err(void)
{
	write(2, "Error\n", 6);
	return (0);
}

///////// print stack ///////////////
//
//void	print(t_node **stack_a)
//{
//	t_node	*i;
//
//	i = *stack_a;
//	while (i)
//	{
//		printf("%d\n", i->content);
//		i = i->next;
//	}
//}
//
/////////// main ////////////////////

int	main(int argc, char **argv)
{
	t_s		s;
	t_node	*stack_a;
	t_node	*stack_b;

	s.ac = argc;
	stack_b = NULL;
	s.args = NULL;
	if (stock_args(&s, argc, argv) < 1)
	{
		if (stock_args(&s, argc, argv) == 0)
			err();
		exit (1);
	}
	if (check_if_number(&s) == 0)
		return (err(), 1);
	if (printargs(&s, &stack_a) == 0)
		return (err(), 1);
	assign_index(&stack_a);
	sort(&stack_a, &stack_b);
	return (0);
}
