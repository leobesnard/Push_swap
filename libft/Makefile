SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_strlen.c ft_isprint.c ft_toupper.c ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_putendl_fd.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_memset.c ft_bzero.c ft_calloc.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c


OBJS = ${SRCS:.c=.o}

SRCSBNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJSBNS = ${SRCSBNS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: ${NAME}

.c.o:
	gcc ${CGLAGS} -c $< -o $@

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	
bonus: ${OBJS} ${OBJSBNS}
	ar rc ${NAME} ${OBJS} ${OBJSBNS}

clean:
	rm -f ${OBJS} ${OBJSBNS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re