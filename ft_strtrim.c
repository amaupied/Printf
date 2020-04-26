/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 02:49:24 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:56:40 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strtrim(char const *s)
{
	char	*new;
	size_t	start;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	start = i;
	i = ft_strlen(s);
	if (i == start)
	{
		new = ft_strsub(s, start, 1);
		return (new);
	}
	while (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n')
		i--;
	i = i - start;
	if (!(new = ft_strsub(s, start, i)))
		return (NULL);
	return (new);
}
