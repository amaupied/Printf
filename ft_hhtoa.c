/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:08:03 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/02 21:42:49 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					ft_hhisneg(signed char n)
{
	return (n < (signed char)0 ? 1 : 0);
}

int					ft_sizeuhh_base(unsigned char n, char *base)
{
	int				i;

	i = 0;
	while (n >= (unsigned char)check_base(base))
	{
		i++;
		n = n / (unsigned char)check_base(base);
	}
	return (i);
}

int					ft_sizehh(signed char n)
{
	int				i;

	i = 0;
	if (n > 0)
	{
		while (n > (signed char)9)
		{
			n = n / (signed char)10;
			i++;
		}
	}
	else
	{
		while (n < (signed char)-9)
		{
			n = n / (signed char)10;
			i++;
		}
	}
	return (i);
}

char				*ft_hhtoa(int n)
{
	int				size;
	char			*str;
	signed char		nb;

	nb = (signed char)n;
	size = ft_sizehh(nb) + ft_hhisneg(nb);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (size >= ft_hhisneg(nb))
	{
		if (nb > (signed char)9 || nb < (signed char)-9)
		{
			str[size] = (ft_hhisneg(nb) ? -1 : 1)
				* (nb % (signed char)10) + 48;
			nb = nb / (signed char)10;
		}
		else
			str[size] = (int)(ft_hhisneg(nb) ? -1 : 1) * nb + 48;
		size--;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}

char				*ft_uhhtoa_base(unsigned int n, char *base)
{
	int				size;
	char			*str;
	unsigned char	nb;

	nb = (unsigned char)n;
	size = ft_sizeuhh_base(nb, base);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (size >= 0)
	{
		if (nb >= (unsigned char)check_base(base))
		{
			str[size] = base[nb
				% (unsigned char)check_base(base)];
			nb = nb / (unsigned char)check_base(base);
		}
		else
			str[size] = base[nb];
		size--;
	}
	return (str);
}
