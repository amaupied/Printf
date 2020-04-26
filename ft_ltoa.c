/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:08:03 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/12 19:55:04 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_lisneg(long n)
{
	return (n < (long)0 ? 1 : 0);
}

int			ft_sizeul_base(unsigned long n, char *base)
{
	int		i;

	i = 0;
	while (n >= (unsigned long)check_base(base))
	{
		i++;
		n = n / (unsigned long)check_base(base);
	}
	return (i);
}

int			ft_sizel(long n)
{
	int		i;

	i = 0;
	if (n > 0)
	{
		while (n > (long)9)
		{
			n = n / (long)10;
			i++;
		}
	}
	else
	{
		while (n < (long)-9)
		{
			n = n / (long)10;
			i++;
		}
	}
	return (i);
}

char		*ft_ltoa(long n)
{
	int		size;
	char	*str;

	size = ft_sizel(n) + ft_lisneg(n);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (size >= ft_lisneg(n))
	{
		if (n > (long)9 || n < (long)-9)
		{
			str[size] = (ft_lisneg(n) ? -1 : 1)
			* (n % (long)10) + 48;
			n = n / (long)10;
		}
		else
			str[size] = (int)(ft_lisneg(n) ? -1 : 1) * n + 48;
		size--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char		*ft_ultoa_base(unsigned long n, char *base)
{
	int		size;
	char	*str;

	size = ft_sizeul_base(n, base);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (size >= 0)
	{
		if (n >= (unsigned long)check_base(base))
		{
			str[size] = base[n
			% (unsigned long)check_base(base)];
			n = n / (unsigned long)check_base(base);
		}
		else
			str[size] = base[n];
		size--;
	}
	return (str);
}
