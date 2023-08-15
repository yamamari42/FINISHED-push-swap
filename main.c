/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mmardere <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/07/15 20:52:02 by mmardere		   #+#	  #+#			  */
/*	 Updated: 2023/07/23 21:39:43 by mmardere		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

///////// stocks arguments in a **, splits if one argument //////////////

int	stock_args(t_s *s,int argc, char **argv)
{

	if (argc > 1)
	{
			if (argc == 2)
			{
					int	i, j;
					i = 0;
					j = 0;
					s->args = ft_split(argv[1], ' ');
					if (!s->args)
							err();
					if (s->args[i] == NULL)
					{
							return (0);
					}
					while (s->args[i])
					{
							while (s->args[i][j])
									j++;
							j = 0;
							i++;
					}
					return (1);
			}
			else if (argc > 2)
			{
					int i , j;
					i = 1;
					j = 0;
					s->args = (char **)malloc(argc * sizeof(char*));
					while (argv[i] && argv[i] != NULL)
					{
							s->args[j] = ft_strdup(argv[i]);
							i++;
							j++;
					}
					s->args[j] = NULL;
					return (1);
			}
			return (0);
	}
	return (-1);
}

/////////// print stack ///////////////

void	print(t_node **stack_a)
{
		t_node	*i = *stack_a;
		// printf("***** STACK *****\n");
		while(i)
		{
				printf("%d\n", i->content );
				// printf("%d - ind[%d] - pos(%d) - target_pos(%d) - cost_a(%d) - cost_b(%d)\n", i->content, i->index, i->pos, i->target_pos, i->cost_a, i->cost_b);
				i = i->next;
		}
}

///////////// main ////////////////////

int	main(int argc, char **argv)
{
	t_s	s;
	t_node *stack_a;
	t_node *stack_b;

	s.ac = argc;
	stack_b = NULL;
	s.args = NULL;//MALLOC, TO FREE
	if (stock_args(&s, argc, argv) < 1)
	{
			if (stock_args(&s, argc, argv) == 0)
					err();
			exit (1);
	}
	if (check_if_number(&s) == 0)
	{
			err();
			return (0);
	}
	if (printargs(&s, &stack_a) == 0)
	{
			err();
			return (0);
	}
	assign_index(&stack_a);
	// print(&stack_a);
	sort(&stack_a, &stack_b);
	printf("STACK_A\n");
	print(&stack_a);
	printf("Stack_B");
	print(&stack_b);

	return (1);
}

/////////////////////////////////
/// to do:
///
/// - frees
/// - norminette
/// - checker
/// - sort amongst files
/// - errors
/////////////////////////////////



///////////////////////////////////////////////////////////////
//	assign_index(&stack_a);
//	while (stack_a)
//	{
//			printf("[%d]: %d\n", stack_a->index, stack_a->content);
//			stack_a = stack_a->next;
//	}
/*	pb(&stack_a, &stack_b);
	printf("head of stack b: %d\nnew head of stack a: %d\n", stack_b->content, stack_a->content);
	pb(&stack_a, &stack_b);
	printf("head of stack b: %d\nnew head of stack a: %d\n", stack_b->content, stack_a->content);
	ss(&stack_a, &stack_b);
	printf("stack a: 1- %d , 2- %d\n", stack_a->content, stack_a->next->content);
	printf("stack b: 1- %d , 2- %d\n", stack_b->content, stack_b->next->content);
	*/
//	rra(&stack_a);
//	printf("stack a: 1- %d , 2- %d, 3 - %d\n", stack_a->content, stack_a->next->content, stack_a->next->next->content);
//
//
/*	give_index();
	if (val == 2)
	{
		if (check_order == 1)
			do_sa;
	}
	else if (val == 3)
	{
		if (check_order == 1)
			do_short_algo();
	}
	else
	{
		if (check_order == 1)
			do_long_algo();
	}
*/
