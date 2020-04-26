/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:34:00 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:46:56 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (!(tmp = (unsigned char *)ft_strnew(n)))
		return ("\0");
	i = 0;
	while (i < n)
	{
		tmp[i] = ((unsigned char *)src)[i];
		i++;
	}
	i--;
	while (i + 1 > 0)
	{
		((unsigned char *)dest)[i] = tmp[i];
		i--;
	}
	free(tmp);
	return (dest);
}
