/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:47:20 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flags(t_printf *data, char **format)
{
	while (**format == '-' || **format == '0')
	{
		if (data->flags == '-')
			data->flags = '-';
		else
			data->flags = **format;
		(*format)++;
	}
}

void	ft_width(t_printf *data, char **format)
{
	if (data->width > 0)
		return ;
	data->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

void	ft_precision(t_printf *data, char **format)
{
	if (data->precision > 0)
		return ;
	if (**format != '.')
		return ;
	data->precision = 0;
	(*format)++;
	data->precision = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

void	ft_type(t_printf *data, char **format)
{
	data->type = **format;
	(*format)++;
}

void	ft_stars(t_printf *data, char **format, va_list arg)
{
	if (**format == '*')
	{
		data->width = va_arg(arg, int);
		if (data->width < 0)
		{
			data->flags = '-';
			data->width *= -1;
		}
		(*format)++;
	}
	if (**format == '.' && *(*format + 1) == '*')
	{
		data->precision = va_arg(arg, int);
		(*format) += 2;
	}
}
