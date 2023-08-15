/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:51:53 by mmardere          #+#    #+#             */
/*   Updated: 2022/12/01 11:35:25 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*bg;
	char	*lt;

	i = 0;
	bg = (char *)big;
	lt = (char *)little;
	if (len == 0 && (!bg || !lt))
		return (NULL);
	if (lt[0] == '\0')
		return (&bg[i]);
	while (bg[i] != '\0' && i < len)
	{
		j = 0;
		while (bg[i + j] == lt[j] && i + j < len)
		{
			j++;
			if (lt[j] == '\0')
				return (&bg[i]);
		}
		i++;
	}
	return (NULL);
}
