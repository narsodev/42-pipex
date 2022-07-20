NAME = pipex

SRC = pipex.c

OBJS = pipex.o

CC = gcc

INCLUDE = -I libft -L libft -l ft

%.o:	%.c
	$(CC) -I libft -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(INCLUDE) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

.PHONY: all bonus clean fclean re
