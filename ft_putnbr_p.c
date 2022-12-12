/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 01:09:10 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_p(t_printf *data, unsigned long n)
{
	unsigned long r;

	r = n;
	if (r < 16)
	{
		if (r < 10)
			ft_putchar(data, r + 48);
		else
			ft_putchar(data, r + 87);
		return ;
	}
	ft_putnbr_p(data, r / 16);
	ft_putnbr_p(data, r % 16);
}
