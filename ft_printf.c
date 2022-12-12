/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:29:02 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(t_printf *data, char c)
{
	write(1, &c, 1);
	data->length += 1;
}

void	ft_zero_struct(t_printf *data)
{
	data->flags = '\0';
	data->width = 0;
	data->precision = -1;
	data->type = 0;
}

int		ft_printf_go(char **format, va_list arg)
{
	t_printf	data;

	data.length = 0;
	ft_zero_struct(&data);
	while (**format)
	{
		if (**format != '%')
		{
			ft_putchar(&data, **format);
			(*format)++;
		}
		else if (**format == '%')
		{
			(*format)++;
			ft_parser(format, &data, arg);
		}
	}
	return (data.length);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			res;

	res = 0;
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	res += ft_printf_go((char **)&format, arg);
	va_end(arg);
	return (res);
}
