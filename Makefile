SRCS = srcs/*.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBFT = libft
LIBFLAGS = -L./libft -l$(LIBFT)
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c ${LIBFLAGS} $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} ${B_OBJS}
	@$(MAKE) -C ${LIBFT} clean

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C ${LIBFT} fclean

re: fclean all

libft.a:
	@$(MAKE) -C ${LIBFT} bonus
	@ranlib $(LIBFT)/$(LIBFT).a

${NAME}: libft.a ${OBJS}
	@ar rcs -o ${NAME} ${OBJS}

norme:
	watch norminette

.PHONY = ${NAME} clean fclean re all debug norme libft.a