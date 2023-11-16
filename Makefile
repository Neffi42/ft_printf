# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 21:49:37 by abasdere          #+#    #+#              #
#    Updated: 2023/11/16 10:24:44 by abasdere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c \
		ft_printf_utils.c \
		ft_putnbr_base.c \
		put_unbr_base.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
TEST = test
LIBFT = libft
LIBFLAGS = -L. -lftprintf
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: ${NAME} Makefile

%.o: %.c Makefile
	@echo "-Compiling $^"
	@${CC} ${CFLAGS} -c $<

clean:
	@${RM} ${OBJS} ${B_OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all Makefile

${NAME}: ${OBJS}
	@echo "-Creating ${NAME}"
	@ar rcs ${NAME} ${OBJS}

.PHONY = clean fclean re all