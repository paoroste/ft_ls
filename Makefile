# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paoroste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 16:53:04 by paoroste          #+#    #+#              #
#    Updated: 2017/09/28 18:33:53 by paoroste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIB_PATH = libft/
LIB = $(LIB_PATH)/libft.a
FLAGS = -Wall -Wextra -Werror

SRC = ft_ls_sort.c main.c ft_error.c get_info.c ft_ls.c\
	  erase.c get_time.c get_more_info.c put_time.c

all: $(NAME)

$(NAME):
	@echo "\033[31m" "Compiling" [ $(NAME) ].
	make -C $(LIB_PATH)
	@gcc $(SRC) $(LIB) -o $(NAME)
	@echo "\033[32m" "ft_ls has been Created"

clean:
	@echo "\033[34m" "Deleting"
	make -C $(LIB_PATH) clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all
