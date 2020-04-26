/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:00:45 by amaupied          #+#    #+#             */
/*   Updated: 2019/04/30 00:08:20 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i] != '\0')
		i = i + 1;
	if ((str = (char *)malloc(sizeof(char) * i + 1)) == 0)
		return (NULL);
	while (i >= 0)
	{
		str[i] = src[i];
		i = i - 1;
	}
	return (str);
}
