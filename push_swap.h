/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:52:35 by mmardere          #+#    #+#             */
/*   Updated: 2023/07/23 21:31:10 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define INT_MAX  2147483647
# define INT_MIN  (-INT_MAX - 1)



typedef	struct s_node
{
		int	content;
		int index;
		int pos;
//		int	to_top_a;//number of moves to be made to get the element on top of the stack A
		int	to_top_b;//number of moves to be made to get the element on top of the stack B
		int	target_pos;
		int	cost_a;
		int	cost_b;
		struct s_node *next;
}	t_node;



typedef struct structure
{
		char	**args;
		int	ac;
}	t_s;




/*typedef struct s_stack
{
	int			val;		//le nombre a trier
	int			index;		//son index dans la liste
	int			pos;		//pos actuelle dans sa stack
	int			target_pos;	//pour les elem de stack B,la pos cible dans la stack A ou elle devrait etre
	int			cost_a;		//nombre d'actions pour pivoter la stack A afin que l'element
						//a la pos cible ateigne le sommet de sack A
	int			cost_b;		//nombre d'actions pour pivoter la stack B afin que l'element
						//a la pos cible ateigne le sommet de sack A
	struct	s_stack	*next;
}	t_stack;
*/

int	err(void);
int	stock_args(t_s *s, int argc, char **argv);
int	check_if_number(t_s *s);
int	check_double(t_node **stack_a);
int	printargs(t_s *s, t_node **stack_a);
int	stack_size(t_node *stack);
long long int	upgraded_atoi(const char *n);
int	check_if_sorted(t_node **stack_a);
int	sort(t_node **stack_a, t_node **stack_b);
int lowest_index(t_node **stack_a);
int	highest_index(t_node *stack);
t_node	*do_atoi(t_s *s);
t_node	*newnode(int content);
t_node	*get_tail(t_node *stack);
t_node	*get_node_before_tail(t_node *stack);
void	node_add_back(t_node **lst, t_node *new);
void	push(t_node **src, t_node **dest);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	swap(t_node *node);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rev_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	do_small_algo(t_node **stack_a);
void	assign_index(t_node **stack_a);
void	do_big_algo(t_node **stack_a, t_node **stack_b);
void	pb_leave_three(t_node **stack_a, t_node **stack_b);
void	find_pos(t_node **stack);
void	get_target_pos(t_node **stack_a, t_node **stack_b);
void	get_to_top_of_b(t_node **stack_b);
void	do_move(t_node **a, t_node **b, int cost_a, int cost_b);



void	print(t_node **stack_a);//to delete

#endif