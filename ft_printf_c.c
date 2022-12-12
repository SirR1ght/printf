/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 07:03:54 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_c(t_printf *data, int c)
{
	int		spaces;
	char	flag;

	spaces = data->width;
	flag = data->flags;
	while (--spaces > 0 && flag != '-')
		ft_putchar(data, flag == '0' ? '0' : ' ');
	ft_putchar(data, c);
	while (--spaces >= 0)
		ft_putchar(data, ' ');
}
