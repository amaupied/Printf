/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 02:49:24 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:56:55 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strtrimc(char const *s, int c)
{
	char	*new;
	size_t	start;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	start = i;
	i = ft_strlen(s);
	if (i == start)
		return ("\0");
	while (s[i - 1] == c)
		i--;
	i = i - start;
	if (!(new = ft_strsub(s, start, i)))
		return (NULL);
	return (new);
}
