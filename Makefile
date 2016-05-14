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
_SRC		=	termcaps/ft_termcaps_key.c\
				termcaps/ft_termcaps_move.c\
				termcaps/ft_termcaps_select.c\
				termcaps/ft_termcaps_utils.c\
				ft_event.c\
				ft_init.c\
				ft_select.c\
				ft_utils.c
SRC			= $(addprefix srcs/,$(_SRC))
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= -Llibft -lft -Ilibft -lncurses

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
