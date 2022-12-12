/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:35:33 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long	ft_nbrlen(long n)
{
	long i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
