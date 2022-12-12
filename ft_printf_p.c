/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 03:58:09 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_p(t_printf *data, unsigned long nbr)
{
	char	flag;
	int		spaces;

	flag = data->flags;
	spaces = data->width - ft_nbrlen_p(nbr) - 1;
	if (nbr == 0 && data->precision > -1)
		spaces++;
	if (data->width < ft_nbrlen_p(nbr))
		spaces = 0;
	while (--spaces > 0 && flag != '-')
		ft_putchar(data, ' ');
	ft_putchar(data, '0');
	ft_putchar(data, 'x');
	if (!(nbr == 0 && data->precision > -1))
		ft_putnbr_p(data, nbr);
	while (--spaces >= 0)
		ft_putchar(data, ' ');
}
