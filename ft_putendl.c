/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:08:04 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:59:16 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putendl(char const *str)
{
	if (str)
	{
		ft_putstr(str);
		ft_putchar('\n');
	}
}