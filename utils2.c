/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:25:13 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/10 23:19:00 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

t_flag		*init_flag(void)
{
	t_flag	*flag;

	if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
		return (NULL);
	flag->str = ft_strnew(0);
	flag->conv = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->space = 0;
	flag->precis = 0;
	flag->lefted = 0;
	flag->sign = 0;
	flag->diez = 0;
	flag->llhh = 0;
	flag->lenght = 0;
	flag->bigl = 0;
	return (flag);
}

void		free_flag(t_flag *flag)
{
	if (flag)
	{
		if (flag->str)
			free(flag->str);
		flag->zero = 0;
		flag->width = 0;
		flag->lenght = 0;
		flag->precis = 0;
		flag->diez = 0;
		flag->sign = 0;
		flag->lefted = 0;
		flag->space = 0;
		flag->conv = 0;
		flag->bigl = 0;
		flag->size = 0;
		free(flag);
		flag = NULL;
	}
	return ;
}

int			assign_llhh(int nb, char *str)
{
	if (*str == 'h' && *(str + 1) == 'h')
		(nb == 0 ? nb = 1 : 1);
	else if (*str == 'h')
		(nb < 2 ? nb = 2 : 1);
	else if (*str == 'l' && *(str + 1) == 'l')
		(nb < 4 ? nb = 4 : 1);
	else if (*str == 'l')
		(nb < 3 ? nb = 3 : 1);
	return (nb);
}

int			xnotnull(char *str)
{
	int		i;
	int		lenght;

	i = 0;
	lenght = ft_strlen(str);
	while (i < lenght)
	{
		if (ft_strchr("123456789abcdefABCDEF", str[i]))
			return (1);
		i++;
	}
	return (0);
}

char		*ft_precis(t_flag *flag, char *str)
{
	char	*to_free;

	if (flag->precis > 1 && ft_strchr("pdiouxX", flag->conv) && flag->precis
	- (ft_strchr("+- ", str[0]) ? 0 : 1) <= (int)ft_strlen(str))
		return (str);
	if ((flag->precis == 1 && ft_strchr("pdiouxX", flag->conv)
	&& !xnotnull(str)) || (flag->precis == 1 && flag->conv == 's'))
		str = ft_strnew_free(0, str);
	else if (ft_strchr("pdiouxX", flag->conv))
		str = ft_joinzeros(str, flag->precis - (ft_strchr("+- ",
		str[0]) ? 0 : 1));
	else if (flag->conv == 's' && flag->precis - 1 < (int)ft_strlen(str))
	{
		to_free = str;
		str = ft_strsub(str, 0, flag->precis - 1);
		ft_strdel(&to_free);
	}
	return (str);
}
