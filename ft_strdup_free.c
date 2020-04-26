/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:39:16 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/09 16:06:36 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

char		*ft_strdup_free(const char *src, char *to_free)
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
	ft_strdel(&to_free);
	return (str);
}
