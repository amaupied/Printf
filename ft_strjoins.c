/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:14:30 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/11 23:38:08 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strjoinsign(char *str)
{
	char	*new;

	if (str[0] == '-')
		return (str);
	new = ft_strjoin("+", str);
	ft_strdel(&str);
	return (new);
}

char		*ft_joinzeros(char *str, int size)
{
	int		i;
	char	*new;
	int		j;

	if ((j = (int)ft_strlen(str)) >= size)
		return (str);
	i = 0;
	if (!(new = ft_strnew(size)))
		return (NULL);
	if (str[0] == '-' || str[0] == '+')
		new[0] = str[i++];
	j = size - j + i;
	while (i < j)
		new[i++] = '0';
	j = i - (ft_strchr("+- ", str[0]) ? 1 : 0);
	while (i < size)
	{
		new[i] = str[i - j];
		i++;
	}
	ft_strdel(&str);
	return (new);
}

char		*ft_strjoinright(char *str, int size)
{
	int		i;
	int		j;
	char	*new;

	if (!size)
		size++;
	if (size <= (int)ft_strlen(str))
		return (str);
	if (!(new = ft_strnew(size)))
		return (NULL);
	i = 0;
	j = size - (int)ft_strlen(str);
	while (i < j)
		new[i++] = ' ';
	j = 0;
	while (i < size)
	{
		new[i] = str[j];
		i++;
		j++;
	}
	ft_strdel(&str);
	return (new);
}

char		*ft_strjoinleft(char *str, int size)
{
	int		i;
	char	*new;

	if (!(new = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		new[i] = str[i];
		i++;
	}
	while (i < size)
		new[i++] = ' ';
	ft_strdel(&str);
	return (new);
}

char		*ft_strjoinchar(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	while (i < (int)ft_strlen(str))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	return (new);
}
