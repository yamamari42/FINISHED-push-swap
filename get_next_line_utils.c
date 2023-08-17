/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:29:45 by mmardere          #+#    #+#             */
/*   Updated: 2023/01/12 19:42:23 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ftstrlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ftstrjoin(char *s1, char *buff)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !buff)
		return (NULL);
	str = malloc((sizeof(char) * (ftstrlen(s1) + ftstrlen(buff) + 1)));
	if (!str)
		return (NULL);
	i = -1;
	if (s1)
	{
		while (s1[++i])
			str[i] = s1[i];
	}
	j = 0;
	while (buff[j])
		str[i++] = buff[j++];
	str[ftstrlen(s1) + ftstrlen(buff)] = '\0';
	return (free(s1), str);
}

char	*ftstrchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[i]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
