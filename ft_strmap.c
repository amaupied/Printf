/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:18:16 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 18:55:17 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strmap(char const *str, char (*f)(char))
{
	char	*new;
	int		i;

	if (!str || !f)
		return (NULL);
	i = ft_strlen(str);
	if (!(new = ft_strnew(i)))
		return (NULL);
	new = ft_strcpy(new, str);
	i = 0;
	while (new[i])
	{
		new[i] = f(new[i]);
		i++;
	}
	return (new);
}
