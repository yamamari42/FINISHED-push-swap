/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:45:36 by mmardere          #+#    #+#             */
/*   Updated: 2022/11/30 21:23:52 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] != '\0' && (ft_strchr(set, s1[i])))
		i++;
	while (j > i && ft_strrchr(set, s1[j - 1]))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (str == 0)
		return (0);
	while (i < j)
	{
		str[c] = s1[i];
		i++;
		c++;
	}
	str[c] = '\0';
	return (str);
}
