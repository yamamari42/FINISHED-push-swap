/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:41:40 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/17 14:32:39 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"
#include "push_swap.h"

////////// do the move //////////////

void	exec_move(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n"))
		ch_sa(stack_a);
	else if (ft_strcmp(line, "sb\n"))
		ch_sb(stack_b);
	else if (ft_strcmp(line, "ss\n"))
		ch_ss(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n"))
		ch_ra(stack_a);
	else if (ft_strcmp(line, "rb\n"))
		ch_rb(stack_b);
	else if (ft_strcmp(line, "rr\n"))
		ch_rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n"))
		ch_rra(stack_a);
	else if (ft_strcmp(line, "rrb\n"))
		ch_rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n"))
		ch_rrr(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n"))
		ch_pa(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n"))
		ch_pb(stack_a, stack_b);
}
