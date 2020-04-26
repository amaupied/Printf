/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:25:03 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/12 20:07:05 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdio.h>

static int	g_charnull;

char		*ft_null(char *str)
{
	char	*new;

	new = ft_strdup("^@");
	g_charnull++;
	ft_strdel(&str);
	return (new);
}

char		*strjoin_options(char *new, t_flag *flag)
{
	if (ft_strchr("di", flag->conv) && flag->sign)
		new = ft_strjoinsign(new);
	else if (ft_strchr("di", flag->conv) && flag->space && new[0] != '-')
		new = ft_strjoinright(new, ft_strlen(new) + 1);
	if (!flag->lefted && !flag->precis && flag->zero)
		new = ft_joinzeros(new, flag->width - (flag->conv == 'x'
		&& flag->diez ? 2 : 0));
	if (new[0] && flag->precis > 0)
		new = ft_precis(flag, new);
	if ((ft_strchr("pxX", flag->conv) && flag->diez && xnotnull(new))
	|| flag->conv == 'p')
		new = ft_strjoin_free((ft_strchr("xp", flag->conv) ? "0x" : "0X"),
		new, new);
	if (flag->conv == 'c' && !flag->str[0])
		new = ft_null(new);
	if (flag->conv == 'o' && flag->diez && !(flag->precis > 1) && (xnotnull(new)
	|| flag->precis == 1))
		new = ft_joinzeros(new, ft_strlen(new) + 1);
	if (flag->width >= (int)ft_strlen(new) && flag->lefted && flag->conv != '%')
		new = ft_strjoinleft(new, flag->width + ((flag->conv == 'c'
		&& !ft_strcmp(new, "^@")) ? 1 : 0));
	else if (flag->width > 0 && flag->conv != '%')
		new = ft_strjoinright(new, flag->width + ((flag->conv == 'c'
		&& !ft_strcmp(new, "^@")) ? 1 : 0));
	return (new);
}

char		*strjoin_flag(char *buffer, t_flag *flag)
{
	char	*new;

	new = ft_strdup(flag->str);
	new = strjoin_options(new, flag);
	if (!is_flag(flag->conv) || flag->conv == 0)
		new = ft_strdup_free(buffer, new);
	else
		new = ft_strjoin_free(buffer, new, new);
	return (new);
}

int			printage(char *buffer)
{
	int		i;
	int		j;

	i = ft_strlen(buffer) - g_charnull;
	if (!g_charnull)
		write(1, buffer, i);
	else
	{
		j = 0;
		while (buffer[j])
		{
			if (g_charnull && buffer[j] == '^' && buffer[j + 1] == '@'
			&& j++ > -1)
			{
				ft_putchar(0);
				g_charnull--;
			}
			else
				ft_putchar(buffer[j]);
			j++;
		}
	}
	ft_strdel(&buffer);
	return (i);
}

int			ft_printf(const char *ptr, ...)
{
	int		i;
	t_flag	*flag;
	char	*buffer;
	char	*to_free;
	va_list	list;

	va_start(list, ptr);
	i = 0;
	g_charnull = 0;
	buffer = ft_strnew(0);
	while (ptr[i] != '\0')
	{
		to_free = buffer;
		if (ptr[i] == '%' && (flag = convert_flag((char *)ptr + i, list)))
		{
			buffer = strjoin_flag(buffer, flag);
			i = i + flag->lenght + (ptr[i + flag->lenght] == '\0' ? 0 : 1);
			free_flag(flag);
		}
		else if (ptr[i] != '\0')
			buffer = ft_strjoinchar(buffer, ptr[i++]);
		ft_strdel(&to_free);
	}
	va_end(list);
	return ((i = printage(buffer)));
}
