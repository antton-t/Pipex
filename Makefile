#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antton-t <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 18:41:25 by antton-t          #+#    #+#              #
#    Updated: 2021/10/22 19:00:05 by antton-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS	= main.c \
	srcs/ft_tools.c \
	srcs/ft_pipex.c \
	srcs/ft_free_pipex.c \

OBJS	= ${SRCS:.c=.o}

.c.o:
	gcc -Wall -Werror -Wextra -c -I includes $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	clang -Wall -Werror -Wextra ${OBJS} libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	make clean -C libft
	rm -f ${OBJS}

fclean: clean
	make fclean -C libft
	rm -f ${NAME}

re: fclean all

