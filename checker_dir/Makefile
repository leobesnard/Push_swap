SRCDIR = ../SRCS/
OBJDIR = ../bin/
INCDIR = ../include/
FTPATH = ../libft/
INDIR = $(FTPATH)include/
LIBFT = $(FTPATH)libft.a

#################################################################
SRCS = check_arg.c\
	checker/commands_checker.c\
	checker/commands2_checker.c\
	parsing.c\
	checker/checker.c\
	checker/tools.c\

OBJS = ${addprefix $(OBJDIR),$(SRCS:.c=.o)}
#################################################################
CFLAGS = -Wall -Wextra -Werror 
LINK = -lft
CC = gcc -g
INCPATH = -I$(INCDIR) -I$(INDIR)
LIBPATH = -L$(FTPATH)
NAME = checker
#################################################################
all: ${NAME}

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c ${CFLAGS} $(INCPATH) $< -o $@

${NAME}: ${OBJS} $(LIBFT)
	$(CC) ${OBJS} $(LIBFT) $(LIBPATH) $(LINK) -o $(NAME) 

$(LIBFT):
	make -C $(FTPATH)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all libft clean fclean re
