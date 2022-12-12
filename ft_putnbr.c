/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:13:43 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(t_printf *data, long n)
{
	long r;

	r = n;
	if (n < 0)
	{
		ft_putchar(data, '-');
		r = -r;
	}
	if (r < 10)
	{
		ft_putchar(data, r + '0');
		return ;
	}
	ft_putnbr(data, r / 10);
	ft_putnbr(data, r % 10);
}
