SRCS = SRCS/check_arg.c SRCS/commands.c SRCS/commands2.c SRCS/parsing.c SRCS/push_swap.c SRCS/tools.c SRCS/sorting.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: ${NAME}

.c.o:
	gcc -g ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	gcc -g ${OBJS} -o $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re