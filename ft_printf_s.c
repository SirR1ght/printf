/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 07:03:54 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_s(t_printf *data, char *c)
{
	char	flag;
	int		spaces;
	size_t	len;

	if (c == NULL)
		c = "(null)";
	len = ft_strlen(c);
	if ((size_t)data->precision < len)
		len = (size_t)data->precision;
	spaces = data->width - len + 1;
	flag = data->flags;
	if ((size_t)data->width < len)
		spaces = 0;
	while (--spaces > 0 && flag != '-')
		ft_putchar(data, ' ');
	while (*c && len--)
	{
		ft_putchar(data, *c);
		c++;
	}
	while (--spaces >= 0)
		ft_putchar(data, ' ');
}
