/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:46:39 by amaupied          #+#    #+#             */
/*   Updated: 2020/02/24 22:14:53 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int			ft_intisneg(int n)
{
	return (n < 0 ? 1 : 0);
}

int			check_base(char *base)
{
	int		i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int			ft_sizeint_base(unsigned int n, char *base)
{
	int		i;

	i = 0;
	while (n >= (unsigned int)check_base(base))
	{
		n = n / check_base(base);
		i++;
	}
	return (i);
}

char		*ft_itoa_base(unsigned int n, char *base)
{
	int		size;
	char	*str;

	size = ft_sizeint_base(n, base);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	while (size > 0)
	{
		if (n >= (unsigned int)check_base(base))
		{
			str[size] = base[n % check_base(base)];
			n = n / check_base(base);
		}
		else
			str[size] = base[n];
		size--;
	}
	str[size] = base[n];
	return (str);
}
