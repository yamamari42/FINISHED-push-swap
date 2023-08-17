/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <mmardere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:01:22 by mmardere          #+#    #+#             */
/*   Updated: 2023/08/17 15:08:27 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///////// splits if quoted argument //////////////

int	split_args(t_s *s, char **argv)
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

///////// stock arguments in a ** ///////////////////

int    stock_args(t_s *s, int argc, char **argv)
{
    int    i;
    int    j;

    i = 1;
    j = 0;
    if (argc > 1)
    {
        if (argc == 2)
        {
            if (split_args(s, argv) == 1)
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

////////// check if  + or - /////////////////////

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

/////////// check if only numbers ///////////////

int	check_if_number(t_s *s)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (s->args[i])
	{
		count = 0;
		j = -1;
		while (is_sign(s->args[i][++j]) && s->args[i][j + 1] != '\0')
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
