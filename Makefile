# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:27:36 by ngonzale          #+#    #+#              #
#    Updated: 2022/09/22 20:15:02 by ngonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex
BONUS		:= pipex

SRC_DIR		:= src
OBJ_DIR		:= obj

FILES		:= main parser path commands commands_helper exec checker

SRCS		:= $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
OBJS		:= $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

SRC_DIR_BONUS	:= src_bonus
OBJ_DIR_BONUS	:= obj_bonus

FILES_BONUS	:= $(addsuffix _bonus, $(FILES))

SRCS_BONUS	:= $(addsuffix .c, $(addprefix $(SRC_DIR_BONUS)/, $(FILES_BONUS)))
OBJS_BONUS	:= $(addsuffix .o, $(addprefix $(OBJ_DIR_BONUS)/, $(FILES_BONUS)))

LIBFT		:= libft

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

INCLUDE		:= -I $(LIBFT) -I .

LIB			:= -L $(LIBFT) -l ft

RM			:= rm -rf

all:		$(NAME)

clean:
	$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)
	make clean -C $(LIBFT)

fclean:		clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re:			fclean all

$(NAME):	$(OBJS) | $(LIBFT)/libft.a
	gcc $(LIB) -o $(NAME) $^

 
bonus:	$(OBJS_BONUS) | $(LIBFT)/libft.a
	gcc $(LIB) -o $(BONUS) $^

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJS_BONUS): $(OBJ_DIR_BONUS)/%.o : $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR_BONUS):
	mkdir -p $@

dir_bonus: $(OBJ_DIR_BONUS)
dir: $(OBJ_DIR)

bonus_obj: $(OBJS_BONUS)

.PHONY: all clean fclean re
