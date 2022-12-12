/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 22:41:17 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_u(t_printf *data, unsigned int nbr)
{
	int		spaces;
	char	flag;

	flag = data->flags;
	spaces = data->width - ft_nbrlen(nbr) + 1;
	if (nbr == 0 && data->precision > -1 && spaces > 0)
		spaces++;
	if (nbr < 0)
		spaces -= 1;
	while (--spaces > 0 && flag != '-')
		ft_putchar(data, flag == '0' ? '0' : ' ');
	if (!(nbr == 0 && data->precision > -1))
		ft_putnbr(data, nbr);
	while (--spaces >= 0)
		ft_putchar(data, ' ');
}

void	ft_printf_um(t_printf *data, unsigned int nbr)
{
	int		spaces;
	char	flag;

	flag = data->flags;
	spaces = data->width - ft_nbrlen(nbr);
	ft_putchar(data, '-');
	while (--spaces > 0)
		ft_putchar(data, flag);
	ft_putnbr(data, nbr *= -1);
}

void	ft_printf_up(t_printf *data, unsigned int nbr)
{
	int		spaces;
	int		zeroes;
	char	flag;

	flag = data->flags;
	zeroes = data->precision - ft_nbrlen(nbr);
	spaces = data->width - data->precision + 1;
	if (ft_nbrlen(nbr) > data->precision)
		spaces = data->width - ft_nbrlen(nbr) + 1;
	if (nbr < 0)
	{
		ft_putchar(data, '-');
		nbr *= -1;
	}
	while (--spaces > 0 && flag != '-')
		ft_putchar(data, ' ');
	while (--zeroes >= 0)
		ft_putchar(data, '0');
	ft_putnbr(data, nbr);
	while (--spaces >= 0 && flag == '-')
		ft_putchar(data, ' ');
}

void	ft_printf_upm(t_printf *data, unsigned int nbr)
{
	int		spaces;
	int		zeroes;
	char	flag;

	flag = data->flags;
	zeroes = data->precision - ft_nbrlen(nbr);
	spaces = data->width - data->precision;
	if (ft_nbrlen(nbr) > data->precision)
		spaces = data->width - ft_nbrlen(nbr);
	while (--spaces > 0 && flag != '-')
		ft_putchar(data, ' ');
	ft_putchar(data, '-');
	while (--zeroes >= 0)
		ft_putchar(data, '0');
	ft_putnbr(data, nbr *= -1);
	while (--spaces >= 0 && flag == '-')
		ft_putchar(data, ' ');
}
