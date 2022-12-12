/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:47:20 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_choose_print_type(t_printf *data, va_list arg)
{
	char	ch;

	ch = data->type;
	if (ch == 'd' || ch == 'i')
		ft_printf_ifd(data, va_arg(arg, int));
	else if (ch == 'u')
		ft_printf_ifu(data, va_arg(arg, unsigned int));
	else if (ch == 'x' || ch == 'X')
		ft_printf_ifx(data, va_arg(arg, unsigned int));
	else if (ch == 'p')
		ft_printf_p(data, va_arg(arg, unsigned long));
	else if (ch == 'c')
		ft_printf_c(data, va_arg(arg, int));
	else if (ch == '%')
		ft_printf_c(data, '%');
	else if (ch == 's')
		ft_printf_s(data, va_arg(arg, char *));
}

void	ft_parser(char **format, t_printf *data, va_list arg)
{
	ft_zero_struct(data);
	ft_flags(data, format);
	ft_stars(data, format, arg);
	ft_width(data, format);
	ft_precision(data, format);
	ft_type(data, format);
	if (data->precision > -1 && data->flags == '0')
		data->flags = '\0';
	ft_choose_print_type(data, arg);
}
