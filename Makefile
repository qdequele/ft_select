# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 14:57:05 by qdequele          #+#    #+#              #
#    Updated: 2016/03/03 13:07:29 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the program
NAME		= ft_select
_SRC		=
SRC			= $(addprefix srcs/,$(_SRC))
CFLAGS		= -Wall -Wextra -Werror -ggdb -g
LIBFT		= -Llibft -lft -Ilibft

all: $(NAME)

$(NAME):
	@mkdir bin
	@make -C libft
	@gcc $(CFLAGS) $(SRC) -Iincludes -o $(NAME) $(LIBFT)
	@echo $(NAME)" compiled"

clean:
	@make clean -C libft
	@/bin/rm -rf bin
	@echo "Clean all .o files"

fclean:
	@make fclean -C libft
	@/bin/rm -rf bin
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o and .a"

re: fclean all

.PHONY: all, clean, fclean, re