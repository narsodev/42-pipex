# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:27:36 by ngonzale          #+#    #+#              #
#    Updated: 2022/09/21 17:32:12 by ngonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex

SRC_DIR		:= .
OBJ_DIR		:= .

FILES		:= main parser path commands commands_helper exec path checker

SRCS		:= $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))

OBJS		:= $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

INCLUDE	:= -I libft

LIB		:= -L libft -l ft

RM			:= rm -f

all:		$(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

$(NAME):	$(OBJS)
	gcc $(LIB) -o $(NAME) $^


$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c 
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean fclean re
