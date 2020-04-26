/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:33:10 by amaupied          #+#    #+#             */
/*   Updated: 2019/04/30 00:04:05 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != to_find[j] && str[i + 1] != '\0')
			i = i + 1;
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
		{
			j = j + 1;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		i = i + 1;
	}
	return (NULL);
}
