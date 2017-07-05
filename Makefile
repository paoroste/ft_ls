# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paoroste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 16:53:04 by paoroste          #+#    #+#              #
#    Updated: 2017/07/05 20:19:30 by paoroste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror

SRC = ft_ls_sort.c main.c ft_error.c get_info.c ft_ls.c\

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@gcc  $(SRC) -o $(NAME) -L ./libft/ -lft

clean:
	@make -C ./libft/ clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
