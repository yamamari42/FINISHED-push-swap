/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:00:08 by mmardere          #+#    #+#             */
/*   Updated: 2022/11/30 20:13:16 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dst = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}
