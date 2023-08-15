/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:22:03 by mmardere          #+#    #+#             */
/*   Updated: 2022/12/01 14:41:00 by mmardere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char *s, char c)
{
	int	i;
	int	wrdc;

	i = 0;
	wrdc = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wrdc++;
		i++;
	}
	return (wrdc);
}

static int	ft_word_len(char *s, char c, int i)
{
	int	word_len;

	word_len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		word_len++;
	}
	return (word_len);
}

static char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_split_core(char **tab, char *s, char c)
{
	int		k;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (((char *)s)[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (((char *)s)[i])
		{
			tab[j] = malloc((ft_word_len((char *)s, c, i) + 1) * sizeof(char));
			if (!tab[j])
				return (ft_free(tab));
			while (s[i] && s[i] != c)
				tab[j][k++] = s[i++];
			tab[j][k] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wdc;

	if (!s)
		return (NULL);
	wdc = ft_word_count((char *)s, c);
	if (!s)
		return (NULL);
	tab = (char **) malloc(sizeof(char *) * (wdc + 1));
	if (!tab)
		return (NULL);
	ft_split_core(tab, (char *)s, c);
	return (tab);
}
