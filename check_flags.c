/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:58:15 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/12 19:56:11 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int			assign_flag(t_flag *flag, char *str)
{
	int		i;

	i = 0;
	if (ft_strchr("123456789", str[i]))
		flag->width = spe_atoi(str);
	else if (str[i] == ' ')
		flag->space = (!flag->sign ? 1 : flag->space);
	else if (str[i] == '+')
		flag->sign = 1;
	else if (str[i] == '.')
		flag->precis = 1 + ft_atoi(str + 1);
	else if (str[i] == '-')
		flag->lefted = 1;
	else if (str[i] == '#')
		flag->diez = 1;
	else if (str[i] == '0')
		flag->zero = 1;
	else if (ft_strchr("lh", str[i]) || (str[i] == 'L' && (flag->bigl = 1)
	&& -1 > 0))
		flag->llhh = assign_llhh(flag->llhh, str);
	if (ft_strchr("123456789", str[i]) || str[i] == '.')
		i = i + spe_size(str) - 1;
	else if (ft_strncmp("ll", str, 2) == 0 || ft_strncmp("hh", str, 2) == 0)
		i = i + 1;
	return (i + 1);
}

char		*assign_dioux(t_flag *flag, va_list list)
{
	char	*to_free;

	to_free = flag->str;
	if (!flag->llhh)
		flag->str = assign_nohdioux(flag, list);
	else if (flag->llhh == 1)
		flag->str = assign_hhdioux(flag, list);
	else if (flag->llhh == 2)
		flag->str = assign_hdioux(flag, list);
	else if (flag->llhh == 3)
		flag->str = assign_ldioux(flag, list);
	else if (flag->llhh == 4)
		flag->str = assign_lldioux(flag, list);
	ft_strdel(&to_free);
	return (flag->str);
}

char		*assign_csp(t_flag *flag, va_list list)
{
	char	*to_free;
	char	*str;
	char	c;

	to_free = flag->str;
	if (flag->conv == 's')
	{
		if (!(str = va_arg(list, char *)))
			flag->str = ft_strdup("(null)");
		else
			flag->str = ft_strjoin(flag->str, str);
	}
	else if (flag->conv == 'c')
	{
		if (!(c = (unsigned char)va_arg(list, int)))
			flag->str = ft_strnew(0);
		else
			flag->str = ft_strjoinchar(flag->str, c);
	}
	else if (flag->conv == 'p')
		flag->str = ft_ultoa_base((unsigned long)va_arg(list, void *),
		"0123456789abcdef");
	ft_strdel(&to_free);
	return (flag->str);
}

char		*assign_float(t_flag *flag, va_list list)
{
	char	*to_free;

	to_free = flag->str;
	if (!flag->precis)
		flag->str = ft_ftoa(va_arg(list, double), 6);
	else
		flag->str = ft_ftoa(va_arg(list, double), flag->precis - 1);
	(void)list;
	ft_strdel(&to_free);
	return (flag->str);
}

t_flag		*convert_flag(char *str, va_list list)
{
	int		i;
	t_flag	*flag;

	i = 1;
	if (!(flag = init_flag()))
		return (NULL);
	while (is_ok(str[i]))
		i = i + (is_option(str[i]) ? assign_flag(flag, str + i) : 1);
	flag->lenght = i;
	flag->conv = str[i];
	if (str[i] && ft_strchr("diouxX", str[i]))
		flag->str = assign_dioux(flag, list);
	else if (str[i] && ft_strchr("csp", str[i]))
		flag->str = assign_csp(flag, list);
	else if (str[i] == 'f')
		flag->str = assign_float(flag, list);
	else if (flag->conv == '%')
		flag->str = ft_strdup_free("%", flag->str);
	else if (!str[i] || !is_flag(str[i]))
		flag->lenght = flag->lenght - 1;
	return (flag);
}
