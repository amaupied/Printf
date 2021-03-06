/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:35:30 by amaupied          #+#    #+#             */
/*   Updated: 2019/04/30 00:06:33 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		ft_striter(char *str, void (*f)(char *))
{
	size_t	i;

	if (!str || !f)
		return ;
	i = 0;
	while (str[i])
	{
		f(&str[i]);
		i++;
	}
}
