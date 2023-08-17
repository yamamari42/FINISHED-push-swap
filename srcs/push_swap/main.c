/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:41:40 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/16 19:22:08 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/////// free ** /////////////////

void	free_args(t_s *s)
{
	int	i;

	i = 0;
	if (s->args == NULL)
		return ;
	while (s->args[i])
	{
		free(s->args[i]);
		i++;
	}
	free(s->args);
	s->args = NULL;
}

//////// error //////////////////

int	err(void)
{
	write(2, "Error\n", 6);
	return (0);
}

//////////// free stack //////////

void	free_stack(t_node **stack)
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

int check_if_empty(t_s *s)
{
    int i = 0;

    if (!s->args[i])
        return (err(), 1);
    while (s->args[i])
    {
        if (ft_strlen(s->args[i]) == 0)
            return (err(), 1);
        i++;
    }
    return (0);
}

//////////// main ////////////////////

int    main(int argc, char **argv)
{
    t_s        s;
    t_node    *stack_a;
    t_node    *stack_b;

    s.ac = argc;
    stack_b = NULL;
    s.args = NULL;
    if (stock_args(&s, argc, argv) < 1)
    {
        if (stock_args(&s, argc, argv) == 0)
            err();
        free_args(&s);
        exit (1);
    }
    if (check_if_empty(&s) == 1)
        return (free_args(&s), 1);
    if (check_if_number(&s) == 0)
        return (free_args(&s), err(), 1);
    if (printargs(&s, &stack_a) == 0)
        return (free_args(&s), free_stack(&stack_a), err(), 1);
    free_args(&s);
    assign_index(&stack_a);
    sort(&stack_a, &stack_b);
    free_stack(&stack_a);
    return (0);
}
