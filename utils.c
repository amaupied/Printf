/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:25:13 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/10 23:19:00 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_flag(char c)
{
	if (!ft_strchr("diouxXcspf%", c))
		return (0);
	else
		return (1);
}

int		is_ok(char c)
{
	if (c == 0 || !ft_strchr(" 0123456789.-+#hlLjzqt';,", c))
		return (0);
	else
		return (1);
}

int		is_option(char c)
{
	if (c == 0 || !ft_strchr(" 0123456789.-+#hlL", c))
		return (0);
	else
		return (1);
}

int		spe_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (str[i] >= '1' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + str[i] - 48;
			i++;
		}
	}
	return (nb);
}

int		spe_size(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		while (ft_strchr("0123456789", str[i]))
			i++;
	}
	else if (ft_strchr("0123456789", str[i]))
		while (ft_strchr("0123456789", str[i]))
			i++;
	return (i);
}
