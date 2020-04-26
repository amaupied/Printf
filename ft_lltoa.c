/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 21:08:03 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/02 21:05:26 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_sizeull_base(unsigned long long n, char *base)
{
	int		i;

	i = 0;
	while (n >= (unsigned long long)check_base(base))
	{
		i++;
		n = n / (unsigned long long)check_base(base);
	}
	return (i);
}

int			ft_llisneg(long long n)
{
	return (n < (long long)0 ? 1 : 0);
}

int			ft_sizell(long long n)
{
	int		i;

	i = 0;
	if (n > 0)
	{
		while (n > (long long)9)
		{
			n = n / (long long)10;
			i++;
		}
	}
	else
	{
		while (n < (long long)-9)
		{
			n = n / (long long)10;
			i++;
		}
	}
	return (i);
}

char		*ft_lltoa(long long n)
{
	int		size;
	char	*str;

	size = ft_sizell(n) + ft_llisneg(n);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (size >= ft_llisneg(n))
	{
		if (n > (long long)9 || n < (long long)-9)
		{
			str[size] = (ft_llisneg(n) ? -1 : 1)
			* (n % (long long)10) + 48;
			n = n / (long long)10;
		}
		else
			str[size] = (int)(ft_llisneg(n) ? -1 : 1) * n + 48;
		size--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char		*ft_ulltoa_base(unsigned long long n, char *base)
{
	int		size;
	char	*str;

	size = ft_sizeull_base(n, base);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (size >= 0)
	{
		if (n >= (unsigned long long)check_base(base))
		{
			str[size] = base[n
			% (unsigned long long)check_base(base)];
			n = n / (unsigned long long)check_base(base);
		}
		else
			str[size] = base[n];
		size--;
	}
	return (str);
}
