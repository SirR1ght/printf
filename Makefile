# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: SirR1ght <SirR1ght@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 15:30:53 by SirR1ght          #+#    #+#              #
#    Updated: 2022/12/12 20:47:48 by SirR1ght         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

INC		=	libftprintf.h

SRCS 	=	ft_atoi.c \
			ft_isdigit.c \
			ft_parser.c \
			ft_parser_utils.c \
			ft_parser_if.c \
			ft_putnbr.c \
			ft_putnbr_x.c \
			ft_putnbr_p.c \
			ft_printf.c \
			ft_nbrlen.c \
			ft_strlen.c \
			ft_nbrlen_x.c \
			ft_nbrlen_p.c \
			ft_printf_d.c \
			ft_printf_u.c \
			ft_printf_x.c \
			ft_printf_p.c \
			ft_printf_c.c \
			ft_printf_s.c

OBJS	= ${SRCS:.c=.o}

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror

AR		= ar rcs

RM		= rm -f

all:		${NAME}

$(NAME):	${OBJS} ${INC}
			${AR} ${NAME} ${OBJS}

$(OBJS): %.o: %.c
			${CC} ${CFLAGS} -I ${INC} -c $< -o $@

clean:
			${RM} ${OBJS} ${O_BONUS}

fclean: clean
			${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re bonus
