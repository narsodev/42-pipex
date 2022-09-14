NAME = pipex

SRC = main.c args.c utils.c exec.c

OBJS = main.o args.o utils.o exec.o

CC = gcc

INCLUDE = -I libft -L libft -l ft

%.o:	%.c
	$(CC) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(INCLUDE)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

.PHONY: all bonus clean fclean re
