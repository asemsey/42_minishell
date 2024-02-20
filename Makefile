# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 15:14:32 by asemsey           #+#    #+#              #
#    Updated: 2024/02/20 15:31:26 by asemsey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = test.c

LIBFT_PATH = include/libft
LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(NAME): lib
	cc -o $(NAME) $(SRC) $(LIBFT)

lib:
	make all bonus -sC $(LIBFT_PATH)

clean:
	make clean -sC $(LIBFT_PATH)

fclean: clean
	make fclean -sC $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all lib clean fclean re