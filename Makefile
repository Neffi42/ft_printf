SRCS = ft_printf.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBFT = libft
LIBFLAGS = -Llibft -lft
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} ${B_OBJS}
	@$(MAKE) -C ${LIBFT} clean

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ${LIBFT} fclean

re: fclean all

libft.a:
	@$(MAKE) -C ${LIBFT} bonus

${NAME}: libft.a ${OBJS}
	@cp ${LIBFT}/${LIBFT}.a .
	@mv ${LIBFT}.a ${NAME}
	@ar rcs ${NAME} ${OBJS}

norme:
	watch norminette

.PHONY = ${NAME} clean fclean re all debug norme libft.a