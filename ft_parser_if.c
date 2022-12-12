/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:18:50 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_ifd(t_printf *data, int nbr)
{
	if (data->precision > 0 && nbr < 0)
		ft_printf_dpm(data, nbr);
	else if (data->precision > 0)
		ft_printf_dp(data, nbr);
	else if (data->flags == '0' && nbr < 0)
		ft_printf_dm(data, nbr);
	else
		ft_printf_d(data, nbr);
}

void	ft_printf_ifu(t_printf *data, unsigned int nbr)
{
	if (data->precision > 0 && nbr < 0)
		ft_printf_upm(data, nbr);
	else if (data->precision > 0)
		ft_printf_up(data, nbr);
	else if (data->flags == '0' && nbr < 0)
		ft_printf_um(data, nbr);
	else
		ft_printf_u(data, nbr);
}

void	ft_printf_ifx(t_printf *data, unsigned int nbr)
{
	if (data->precision > 0 && nbr < 0)
		ft_printf_xpm(data, nbr);
	else if (data->precision > 0)
		ft_printf_xp(data, nbr);
	else if (data->flags == '0' && nbr < 0)
		ft_printf_xm(data, nbr);
	else
		ft_printf_x(data, nbr);
}
