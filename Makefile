# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paoroste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 16:53:04 by paoroste          #+#    #+#              #
#    Updated: 2017/06/01 13:18:33 by paoroste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror

SRC = ft_ls.c/core.c/tool.c/main.c/ft_error.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@gcc  $(FLAGS) $(SRC) -o $(NAME) -L ./libft/ -lft

clean:
	@make -C ./libft/ clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
