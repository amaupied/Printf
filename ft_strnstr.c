/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:33:10 by amaupied          #+#    #+#             */
/*   Updated: 2019/04/30 00:05:18 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != to_find[j] && str[i + 1] != '\0' && i < n)
			i = i + 1;
		while (str[i + j] == to_find[j] && str[i + j] != '\0' && i + j < n)
		{
			j = j + 1;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		i = i + 1;
	}
	return (NULL);
}
