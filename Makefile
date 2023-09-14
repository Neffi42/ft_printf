SRCS = srcs/*.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS} ${B_OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

${NAME}: ${OBJS}
	@ar rcs -o ${NAME} ${OBJS}

norme:
	watch norminette

.PHONY = ${NAME} clean fclean re all debug norme