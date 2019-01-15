# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 22:33:54 by ggerardy          #+#    #+#              #
#    Updated: 2018/12/13 01:58:26 by ggerardy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIB = ./libft/libft.a
HEADERS = $(wildcard *.h)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	make -C libft/ all
	clang -o fillit $(OBJS) $(LIB) $(FLAGS)

build: $(SRCS) $(HEADERS)
	clang $(FLAGS) -c $(SRCS)

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
