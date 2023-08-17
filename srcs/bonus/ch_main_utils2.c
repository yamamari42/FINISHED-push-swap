/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ch_main_utils2.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: mmardere <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/17 15:59:20 by mmardere	       #+#    #+#	      */
/*   Updated: 2023/08/17 16:01:05 by mmardere         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "bonus_push_swap.h"

///////////////////////////////

void	ch_free_args(t_s *s)
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

///////////////////////////////

int	err(void)
{
	write(2, "Error\n", 6);
	return (0);
}

///////////////////////////////

int	ch_check_if_empty(t_s *s)
{
	int	i;

	i = 0;
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

///////////////////////////////

int	ch_printargs(t_s *s, t_node **stack_a)
{
	*stack_a = ch_do_atoi(s);
	if (ch_check_double(stack_a) == 0)
		return (0);
	return (1);
}

///////////////////////////////

int	ch_check_if_number(t_s *s)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (s->args[i])
	{
		count = 0;
		j = -1;
		while (ch_is_sign(s->args[i][++j]) && s->args[i][j + 1] != '\0')
			count++;
		if (count > 1)
			return (0);
		while (ft_isdigit(s->args[i][j]) && ft_isdigit(s->args[i][j + 1]))
				j++;
		if (!(s->args[i][j] == '\0') && !ft_isdigit(s->args[i][j]))
			return (0);
		if (!(ft_isdigit(s->args[i][j + 1])))
			if (ft_isdigit(s->args[i][j]) && (s->args[i][j + 1] != '\0'))
				return (0);
		i++;
	}
	return (1);
}
