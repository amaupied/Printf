/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:08:03 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/12 19:56:36 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int				ft_fisneg(float n)
{
	return (n < (float)0 ? 1 : 0);
}

int				ft_sizef(float n)
{
	int			i;

	i = 0;
	if (n > 0)
	{
		while (n > (float)9)
		{
			n = n / (float)10;
			i++;
		}
	}
	else
	{
		while (n < (float)-9)
		{
			n = n / (float)10;
			i++;
		}
	}
	return (i);
}

void			ftoa_dec(char *str, float n, int precis, float decim)
{
	int			size;

	size = ft_strlen(str) + ft_fisneg(n) + (precis ? precis + 1 : 0);
	if (precis)
		str[size - precis - 1] = '.';
	while (precis)
	{
		str[size - precis] = (int)decim + 48;
		decim = (decim - (int)decim) * 10;
		precis--;
	}
	if (ft_fisneg(n))
		str[0] = '-';
	return ;
}

char			*ft_ftoa(float n, int precis)
{
	int			size;
	int			res;
	char		*str;
	float		decim;

	decim = (n - (int)n) * 10;
	size = ft_sizef(n) + ft_fisneg(n) + (precis ? precis + 1 : 0);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (size - (precis ? precis + 1 : 0) >= ft_fisneg(n))
	{
		if ((n > (float)9 || n < (float)-9))
		{
			res = n / 10;
			str[size - (precis ? precis + 1 : 0)] = ((ft_fisneg(n) ?
			-1 : 1) * (int)n) - (res * 10) + 48;
			n = n / 10;
		}
		else
			str[size - (precis ? precis + 1 : 0)] = (ft_lisneg(n) ?
			-1 : 1) * n + 48;
		size--;
	}
	ftoa_dec(str, n, precis, decim);
	return (str);
}
