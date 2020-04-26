/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 03:25:14 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/13 19:00:35 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			ft_intisneg(int n)
{
	return (n < 0 ? 1 : 0);
}

static int			ft_sizeint(unsigned int n)
{
	int				i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	int				size;
	char			*str;
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	size = ft_sizeint(nb) + ft_intisneg(n);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (size >= ft_intisneg(n))
	{
		if (nb > 9)
		{
			str[size] = (nb % 10) + 48;
			nb = nb / 10;
		}
		else
			str[size] = nb + 48;
		size--;
	}
	return (str);
}
