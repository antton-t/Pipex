# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antton-t <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 18:41:25 by antton-t          #+#    #+#              #
#    Updated: 2021/10/16 16:59:45 by antton-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = clang
HEAD = -Iinclude -Ilibft
CFLAGS = -Wall -Wextra -g3 -fsanitize=address 

FILES = main.c \
		ft_tools.c \
		ft_pipex.c \

SRC_PATH = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_PATH), $(dir))

OBJ_PATH = objs
OBJ = $(addprefix $(OBJ_PATH)/, $(FILES:%.c=%.o))

all :   $(NAME) 

$(NAME) : libft/libft.a $(OBJ_PATH) $(OBJ) ./include/pipex.h
	$(CC) $(CFLAGS) $(HEAD) $(OBJ) libft/libft.a -o ${NAME}

libft/libft.a : 
	make -C libft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : %.c
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

print:
	@echo $(OBJ)
clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
re: fclean all
