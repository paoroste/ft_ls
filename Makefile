# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paoroste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 16:53:04 by paoroste          #+#    #+#              #
#    Updated: 2017/06/07 18:42:38 by paoroste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror

SRC = ft_ls_sort.c core.c tool.c main.c ft_error.c get_info.c ft_ls.c

all: $(NAME)

$(NAME):
	@make -C ./libft/
	@gcc  $(SRC) -o $(NAME) -L ./libft/ -lft

clean:
	@make -C ./libft/ clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
