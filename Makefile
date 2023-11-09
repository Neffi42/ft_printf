SRCS =	ft_printf.c \
		ft_printf_utils.c \
		ft_putnbr_base.c
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
	@${CC} ${CFLAGS} -c $<

clean:
	@${RM} ${OBJS} ${B_OBJS}
	@$(MAKE) -C ${LIBFT} clean

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ${LIBFT} fclean

re: fclean all Makefile

${LIBFT}.a:
	@$(MAKE) -C ${LIBFT} bonus

${NAME}: ${LIBFT}.a ${OBJS}
	@cp ${LIBFT}/${LIBFT}.a .
	@mv ${LIBFT}.a ${NAME}
	@ar rcs ${NAME} ${OBJS}

${TEST}: re tclean
	@${CC} ${CFLAGS} -g3 ${TEST}.c ${LIBFLAGS} -o ${TEST}

tclean:
	@${RM} ${TEST}

norme:
	watch norminette

.PHONY = ${NAME} clean fclean re all debug norme ${LIBFT}.a ${TEST}