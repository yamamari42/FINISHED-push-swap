/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   bonus_push_swap.h                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: mmardere <mmardere@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/07/15 20:52:35 by mmardere	       #+#    #+#	      */
/*   Updated: 2023/08/16 17:00:32 by mmardere         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef BONUS_PUSH_SWAP_H
# define BONUS_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "push_swap.h"
# include "get_next_line.h"
# include "libft.h"

# define INT_MAX  2147483647
# define INT_MIN -2147483648

void			ch_push(t_node **src, t_node **dest);
void			ch_pa(t_node **stack_b, t_node **stack_a);
void			ch_pb(t_node **stack_a, t_node **stack_b);
void			ch_swap(t_node *node);
void			ch_sa(t_node **stack_a);
void			ch_sb(t_node **stack_b);
void			ch_ss(t_node **stack_a, t_node **stack_b);
void			ch_rotate(t_node **stack);
void			ch_ra(t_node **stack_a);
void			ch_rb(t_node **stack_b);
void			ch_rr(t_node **stack_a, t_node **stack_b);
void			ch_rev_rotate(t_node **stack);
void			ch_rra(t_node **stack_a);
void			ch_rrb(t_node **stack_b);
void			ch_rrr(t_node **stack_a, t_node **stack_b);
void			exec_move(t_node **stack_a, t_node **stack_b, char *line);
int				ch_check_if_empty(t_s *s);
int				ft_strcmp(char *s1, char *s2);
void			ch_free_args(t_s *s);
int	ch_printargs(t_s *s, t_node **stack_a);
int	ch_check_if_number(t_s *s);
int   	ch_stock_args(t_s *s, int argc, char **argv);
int	ch_stack_size(t_node *stack);
int	ch_check_if_sorted(t_node **stack_a);
int	ch_is_sign(char c);
int	ch_check_double(t_node **stack_a);
void	ch_free_stack(t_node **stack);
t_node	*ch_do_atoi(t_s *s);
int	ch_split_args(t_s *s, char **argv);
int	ch_check_if_int_overflow(const char *n, t_s *s);
t_node	*ch_get_tail(t_node *stack);
void	ch_node_add_back(t_node **lst, t_node *new);
t_node	*ch_newnode(int content);
long long int	ch_upgraded_atoi(const char *n);
t_node	*ch_get_node_before_tail(t_node *stack);
#endif
