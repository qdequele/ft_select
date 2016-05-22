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
NAME		=	ft_select
LIB			=	./libft/libft.a
_SRC		=	termcaps/ft_termcaps_hover.c\
				termcaps/ft_termcaps_key.c\
				termcaps/ft_termcaps_move.c\
				termcaps/ft_termcaps_remove.c\
				termcaps/ft_termcaps_select.c\
				termcaps/ft_termcaps_utils.c\
				ft_event.c\
				ft_select.c\
				ft_select_env.c\
				ft_select_errors.c\
				ft_select_show.c \
				ft_select_signals.c

SRC			=	$(addprefix srcs/,$(_SRC))
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I./libft/ -I./includes/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@gcc $(CFLAGS) $(OBJ) $(LIB) -L /usr/lib -ltermcap $(INCLUDES) -o $(NAME)
	@echo $(NAME) " - compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@make clean -C libft
	@/bin/rm -rf $(OBJ)
	@echo $(NAME) " - Clean all .o files"

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo $(NAME) " - Clean executable"

re: fclean all

.PHONY: all, clean, fclean, re
