/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:04:34 by mmardere          #+#    #+#             */
/*   Updated: 2022/12/01 11:30:27 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	if (size == 0 && (!dst || !src))
		return (0);
	i = ft_strlen(dst);
	j = 0;
	dst_len = ft_strlen(dst);
	if (i < size)
	{
		while (src[j] != '\0' && i < (size - 1))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (size == 0 || ft_strlen(dst) > size)
		return (ft_strlen(src) + size);
	return (dst_len + ft_strlen(src));
}
