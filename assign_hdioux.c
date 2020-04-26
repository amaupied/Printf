/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_hdioux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaupied <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:58:15 by amaupied          #+#    #+#             */
/*   Updated: 2020/03/12 19:56:11 by amaupied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*assign_nohdioux(t_flag *flag, va_list list)
{
	if (flag->conv == 'd' || flag->conv == 'i')
		flag->str = ft_itoa(va_arg(list, int));
	else if (flag->conv == 'o')
		flag->str = ft_itoa_base(va_arg(list, unsigned int), "01234567");
	else if (flag->conv == 'u')
		flag->str = ft_itoa_base(va_arg(list, unsigned int),
		"0123456789");
	else if (flag->conv == 'x')
		flag->str = ft_itoa_base(va_arg(list, unsigned int),
		"0123456789abcdef");
	else if (flag->conv == 'X')
		flag->str = ft_itoa_base(va_arg(list, unsigned int),
		"0123456789ABCDEF");
	return (flag->str);
}

char	*assign_hdioux(t_flag *flag, va_list list)
{
	if (flag->conv == 'd' || flag->conv == 'i')
		flag->str = ft_htoa(va_arg(list, int));
	else if (flag->conv == 'o')
		flag->str = ft_uhtoa_base(va_arg(list, unsigned int), "01234567");
	else if (flag->conv == 'u')
		flag->str = ft_uhtoa_base(va_arg(list, unsigned int), "0123456789");
	else if (flag->conv == 'x')
		flag->str = ft_uhtoa_base(va_arg(list, unsigned int),
		"0123456789abcdef");
	else if (flag->conv == 'X')
		flag->str = ft_uhtoa_base(va_arg(list, unsigned int),
		"0123456789ABCDEF");
	return (flag->str);
}

char	*assign_hhdioux(t_flag *flag, va_list list)
{
	if (flag->conv == 'd' || flag->conv == 'i')
		flag->str = ft_hhtoa(va_arg(list, int));
	else if (flag->conv == 'o')
		flag->str = ft_uhhtoa_base(va_arg(list, unsigned int), "01234567");
	else if (flag->conv == 'u')
		flag->str = ft_uhhtoa_base(va_arg(list, unsigned int), "0123456789");
	else if (flag->conv == 'x')
		flag->str = ft_uhhtoa_base(va_arg(list, unsigned int),
		"0123456789abcdef");
	else if (flag->conv == 'X')
		flag->str = ft_uhhtoa_base(va_arg(list, unsigned int),
		"0123456789ABCDEF");
	return (flag->str);
}

char	*assign_ldioux(t_flag *flag, va_list list)
{
	if (flag->conv == 'd' || flag->conv == 'i')
		flag->str = ft_ltoa(va_arg(list, long int));
	else if (flag->conv == 'o')
		flag->str = ft_ultoa_base(va_arg(list, long long int), "01234567");
	else if (flag->conv == 'u')
		flag->str = ft_ultoa_base(va_arg(list, long long int),
		"0123456789");
	else if (flag->conv == 'x')
		flag->str = ft_ultoa_base(va_arg(list, long long int),
		"0123456789abcdef");
	else if (flag->conv == 'X')
		flag->str = ft_ultoa_base(va_arg(list, long long int),
		"0123456789ABCDEF");
	return (flag->str);
}

char	*assign_lldioux(t_flag *flag, va_list list)
{
	if (flag->conv == 'd' || flag->conv == 'i')
		flag->str = ft_lltoa(va_arg(list, long long int));
	else if (flag->conv == 'o')
		flag->str = ft_ulltoa_base(va_arg(list, unsigned long long int),
		"01234567");
	else if (flag->conv == 'u')
		flag->str = ft_ulltoa_base(va_arg(list, unsigned long long int),
		"0123456789");
	else if (flag->conv == 'x')
		flag->str = ft_ulltoa_base(va_arg(list, unsigned long long int),
		"0123456789abcdef");
	else if (flag->conv == 'X')
		flag->str = ft_ulltoa_base(va_arg(list, unsigned long long int),
		"0123456789ABCDEF");
	return (flag->str);
}
