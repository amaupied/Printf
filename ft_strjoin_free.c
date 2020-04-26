/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:37:21 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/09 19:38:30 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strjoin_free(char const *s1, char const *s2, char *to_free)
{
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = ft_strnew(sizeof(char) * (i))))
		return (NULL);
	ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	ft_strdel(&to_free);
	return (str);
}
