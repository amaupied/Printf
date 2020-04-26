/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:16:20 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:58:57 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void		ft_putstr_fd(const char *str, int fd)
{
	int		i;

	if (str)
	{
		i = ft_strlen(str);
		write(fd, str, i);
	}
}
