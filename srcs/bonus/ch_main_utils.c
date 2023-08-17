/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:54:31 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/17 15:36:15 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

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

int	err(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int ch_check_if_empty(t_s *s)
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
int	ch_printargs(t_s *s, t_node **stack_a)
{
	*stack_a = ch_do_atoi(s);

	if (ch_check_double(stack_a) == 0)
		return (0);
	return (1);
}

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
int   	ch_stock_args(t_s *s, int argc, char **argv)
{
    int    i;
    int    j;

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

int	ch_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}
void	ch_free_stack(t_node **stack)
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
t_node	*ch_do_atoi(t_s *s)
{
	t_node	*stack;
	t_node	*tmp;
	int		i;

	stack = NULL;
	i = 0;
	while (s->args[i])
	{
		tmp = ch_newnode(ch_check_if_int_overflow(s->args[i], s));
		tmp->index = 0;
		ch_node_add_back(&stack, tmp);
		i++;
	}
	return (stack);
}
int	ch_split_args(t_s *s, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s->args = ft_split(argv[1], ' ');
	if (!s->args)
	{
		err();
		return (0);
	}
	if (s->args[i] == NULL)
		return (1);
	while (s->args[i])
	{
		while (s->args[i][j])
			j++;
		j = 0;
		i++;
	}
	return (1);
}
t_node	*ch_get_tail(t_node *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}
int	ch_check_if_int_overflow(const char *n, t_s *s)
{
	long long int	res;

	res = ch_upgraded_atoi(n);
	if (res >= INT_MIN && res <= INT_MAX)
		return (res);
	else
	{
		err();
		ch_free_args(s);
		exit (1);
	}
}
t_node	*ch_newnode(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
void	ch_node_add_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
t_node	*ch_get_node_before_tail(t_node *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

long long int	ch_upgraded_atoi(const char *n)
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
