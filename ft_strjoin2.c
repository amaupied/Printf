/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:22:45 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/09 19:37:10 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strjoin2(char const *s1, char const *s2, char const *s3)
{
	size_t	i;
	char	*str;
	char	*str2;

	str2 = NULL;
	if (!s1 || !s2 || !s3)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if (!(str = ft_strnew(sizeof(char) * (i))))
		return (NULL);
	if (!(str2 = ft_strnew(sizeof(char) * (ft_strlen(s2) + ft_strlen(s3)))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str2, s2);
	str2 = ft_strcat(str2, s3);
	str = ft_strcat(str, str2);
	ft_strdel(&str2);
	return (str);
}
