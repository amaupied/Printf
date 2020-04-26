/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 23:05:07 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:47:12 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	length;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	length = len_src + size;
	if (size > len_dest)
	{
		length = len_dest + len_src;
		ft_strncat(dest, src, size - len_dest - 1);
	}
	return (length);
}
