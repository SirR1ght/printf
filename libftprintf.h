/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:31:55 by SirR1ght          #+#    #+#             */
/*   Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_printf
{
	char		flags;
	int			width;
	int			precision;
	char		type;
	unsigned	length;
}				t_printf;

void			ft_putchar(t_printf *data, char c);
int				ft_atoi(char *str);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);
long			ft_nbrlen(long n);
long			ft_nbrlen_x(long n);
long			ft_nbrlen_p(unsigned long n);
void			ft_zero_struct(t_printf *data);
void			ft_flags(t_printf *data, char **format);
void			ft_width(t_printf *data, char **format);
void			ft_precision(t_printf *data, char **format);
void			ft_type(t_printf *data, char **format);
void			ft_stars(t_printf *data, char **format, va_list arg);
void			ft_putnbr(t_printf *data, long n);
void			ft_putnbr_x(t_printf *data, long n);
void			ft_putnbr_p(t_printf *data, unsigned long n);
void			ft_printf_d(t_printf *data, long nbr);
void			ft_printf_dm(t_printf *data, long nbr);
void			ft_printf_dp(t_printf *data, long nbr);
void			ft_printf_dpm(t_printf *data, long nbr);
void			ft_printf_u(t_printf *data, unsigned nbr);
void			ft_printf_um(t_printf *data, unsigned nbr);
void			ft_printf_up(t_printf *data, unsigned nbr);
void			ft_printf_upm(t_printf *data, unsigned nbr);
void			ft_printf_x(t_printf *data, unsigned nbr);
void			ft_printf_xm(t_printf *data, unsigned nbr);
void			ft_printf_xp(t_printf *data, unsigned nbr);
void			ft_printf_xpm(t_printf *data, unsigned nbr);
void			ft_printf_p(t_printf *data, unsigned long nbr);
void			ft_printf_c(t_printf *data, int c);
void			ft_printf_s(t_printf *data, char *c);
int				ft_printf_go(char **format, va_list arg);
int				ft_printf(const char *format, ...);
void			ft_choose_print_type(t_printf *data, va_list arg);
void			ft_parser(char **format, t_printf *data, va_list arg);
void			ft_printf_ifd(t_printf *data, int nbr);
void			ft_printf_ifu(t_printf *data, unsigned int nbr);
void			ft_printf_ifx(t_printf *data, unsigned int nbr);
#endif
