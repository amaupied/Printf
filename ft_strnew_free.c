/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:17:55 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:49:19 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strnew_free(int size, char *to_free)
{
	char	*new;

	if (!(new = ft_strnew(size)))
		return (NULL);
	ft_strdel(&to_free);
	return (new);
}
