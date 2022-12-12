/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 01:09:10 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_x(t_printf *data, long n)
{
	long r;

	r = n;
	if (r < 16)
	{
		if (data->type == 'X')
		{
			if (r < 10)
				ft_putchar(data, r + 48);
			else
				ft_putchar(data, r + 55);
			return ;
		}
		if (data->type == 'x')
		{
			if (r < 10)
				ft_putchar(data, r + 48);
			else
				ft_putchar(data, r + 87);
			return ;
		}
	}
	ft_putnbr_x(data, r / 16);
	ft_putnbr_x(data, r % 16);
}
