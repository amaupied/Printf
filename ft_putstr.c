/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:01:13 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:58:44 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void		ft_putstr(char const *str)
{
	int		i;

	if (str)
	{
		i = ft_strlen(str);
		write(1, str, i);
	}
}
