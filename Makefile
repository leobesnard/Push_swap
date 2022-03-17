SRCDIR = SRCS/
OBJDIR = bin/
INCDIR = include/
FTPATH = libft/
INDIR = $(FTPATH)include/
LIBFT = $(FTPATH)libft.a

#################################################################
SRCS = check_arg.c\
	commands.c\
	commands2.c\
	parsing.c\
	tools.c\
	sorting_big.c\
	cost.c\
	mediane.c\
	mediane2.c\
	sorting_small.c\
	push_swap.c\

OBJS = ${addprefix $(OBJDIR),$(SRCS:.c=.o)}
#################################################################
CFLAGS = -Wall -Wextra -Werror 
LINK = -lft
CC = gcc -g
INCPATH = -I$(INCDIR) -I$(INDIR)
LIBPATH = -L$(FTPATH)
NAME = push_swap

all: ${NAME}

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c ${CFLAGS} $(INCPATH) $< -o $@

${NAME}: ${OBJS} $(LIBFT)
	$(CC) ${OBJS} $(LIBFT) $(LIBPATH) $(LINK) -o $(NAME)

$(LIBFT):
	make -C $(FTPATH)

checker:
	make re -C checker_dir/
	cp checker_dir/checker .

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all libft clean fclean re
