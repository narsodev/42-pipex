# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:27:36 by ngonzale          #+#    #+#              #
#    Updated: 2022/09/22 16:26:30 by ngonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex

SRC_DIR		:= src
OBJ_DIR		:= obj

FILES		:= main parser path commands commands_helper exec checker

SRCS		:= $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))

OBJS		:= $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

LIBFT		:= libft

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

INCLUDE		:= -I $(LIBFT) -I .

LIB			:= -L $(LIBFT) -l ft

RM			:= rm -rf

all:		$(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

$(NAME):	$(OBJS) | $(LIBFT)/libft.a
	gcc $(LIB) -o $(NAME) $^
	
$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY: all clean fclean re
