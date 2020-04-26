/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:41:39 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:49:05 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

void	*ft_memalloc(size_t size)
{
	void *str;

	if (!(str = (void *)malloc(size)))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
