/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:08:03 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/02 21:40:53 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					ft_hisneg(short n)
{
	return (n < (short)0 ? 1 : 0);
}

int					ft_sizeuh_base(unsigned short n, char *base)
{
	int				i;

	i = 0;
	while (n >= (unsigned short)check_base(base))
	{
		i++;
		n = n / (unsigned short)check_base(base);
	}
	return (i);
}

int					ft_sizeh(short n)
{
	int				i;

	i = 0;
	if (n > 0)
	{
		while (n > (short)9)
		{
			n = n / (short)10;
			i++;
		}
	}
	else
	{
		while (n < (short)-9)
		{
			n = n / (short)10;
			i++;
		}
	}
	return (i);
}

char				*ft_htoa(int n)
{
	int				size;
	char			*str;
	short			nb;

	nb = (short)n;
	size = ft_sizeh(nb) + ft_hisneg(nb);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (size >= ft_hisneg(nb))
	{
		if (nb > (short)9 || nb < (short)-9)
		{
			str[size] = (ft_hisneg(nb) ? -1 : 1)
			* (nb % (short)10) + 48;
			nb = nb / (short)10;
		}
		else
			str[size] = (int)(ft_hisneg(n) ? -1 : 1) * nb + 48;
		size--;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}

char				*ft_uhtoa_base(unsigned int n, char *base)
{
	int				size;
	char			*str;
	unsigned short	nb;

	nb = (unsigned short)n;
	size = ft_sizeuh_base(nb, base);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (size >= 0)
	{
		if (nb >= (unsigned short)check_base(base))
		{
			str[size] = base[nb
				% (unsigned short)check_base(base)];
			nb = nb / (unsigned short)check_base(base);
		}
		else
			str[size] = base[nb];
		size--;
	}
	return (str);
}
