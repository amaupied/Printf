/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 04:22:48 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:58:08 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		**ft_memwords(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (((unsigned char *)s)[i] == (unsigned char)c && s[i])
			i++;
		if (((unsigned char *)s)[i] != (unsigned char)0)
			words++;
		while (((unsigned char *)s)[i] != (unsigned char)c && s[i])
			i++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * words + 1)))
		return (NULL);
	return (tab);
}

static char		**ft_strsplit2(char const *s, char c, size_t start, size_t word)
{
	char		**tab;
	size_t		i;

	if (!(s = ft_strtrimc(s, c)))
		return ((char **)NULL);
	if (!(tab = ft_memwords(s, c)))
		return ((char **)NULL);
	i = 0;
	while (s[i])
	{
		while (((unsigned char *)s)[i] == (unsigned char)c && s[i])
			i++;
		if (s[i])
			start = i;
		while (((unsigned char *)s)[i] != (unsigned char)c && s[i])
			i++;
		if (!(tab[word] = ft_strsub(s, start, i - start)))
		{
			free(tab);
			return (NULL);
		}
		word++;
	}
	tab[word] = (char *)0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_strsplit2(s, c, 0, 0));
	else
		return (NULL);
}
