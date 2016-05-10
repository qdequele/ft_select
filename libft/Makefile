# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 14:30:45 by qdequele          #+#    #+#              #
#    Updated: 2016/02/26 11:40:08 by qdequele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define the libft
NAME				=	libft.a

#Define FT_ARR
_FT_ARR_SRC			=	ft_count_column_array.c ft_count_raw_array.c\
						ft_free_array.c ft_join_array.c ft_print_array.c

FT_ARR_SRC			=	$(addprefix ft_array/,$(_FT_ARR_SRC))
_FT_ARR_SRC_O		=	$(patsubst %.c,%.o, $(_FT_ARR_SRC))
FT_ARR_SRC_O		=	$(addprefix bin/,$(_FT_ARR_SRC_O))

#Define FT_IS
_FT_IS_SRC			=	ft_isprint.c ft_isalnum.c ft_isascii.c ft_isalpha.c \
						ft_isdigit.c ft_isnegative.c ft_isupper.c ft_islower.c

FT_IS_SRC			=	$(addprefix ft_is/,$(_FT_IS_SRC))
_FT_IS_SRC_O		=	$(patsubst %.c,%.o, $(_FT_IS_SRC))
FT_IS_SRC_O			=	$(addprefix bin/,$(_FT_IS_SRC_O))

#Define FT_LST
_FT_LST_SRC			=	ft_lstnew.c ft_lstdelone.c ft_lstcount.c ft_lstdel.c\
						ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstaddend.c\
						ft_lstsort.c ft_lstreverse.c ft_lstcpy.c

FT_LST_SRC			=	$(addprefix ft_lst/,$(_FT_LST_SRC))
_FT_LST_SRC_O		=	$(patsubst %.c,%.o, $(_FT_LST_SRC))
FT_LST_SRC_O		=	$(addprefix bin/,$(_FT_LST_SRC_O))

#Define FT_MATRIX
_FT_MATRIX_SRC		= ft_matrix_create.c

FT_MATRIX_SRC		=	$(addprefix ft_matrix/,$(_FT_MATRIX_SRC))
_FT_MATRIX_SRC_O	=	$(patsubst %.c,%.o, $(_FT_MATRIX_SRC))
FT_MATRIX_SRC_O		=	$(addprefix bin/,$(_FT_MATRIX_SRC_O))

#Define FT_MEM
_FT_MEM_SRC			=	ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
						ft_memchr.c ft_memcmp.c ft_memdel.c ft_memalloc.c

FT_MEM_SRC			=	$(addprefix ft_mem/,$(_FT_MEM_SRC))
_FT_MEM_SRC_O		=	$(patsubst %.c,%.o, $(_FT_MEM_SRC))
FT_MEM_SRC_O		=	$(addprefix bin/,$(_FT_MEM_SRC_O))

#Define FT_MEM
_FT_PARSER_SRC		=	ft_parser_option.c ft_parser_option_err.c

FT_PARSER_SRC		=	$(addprefix ft_parser/,$(_FT_PARSER_SRC))
_FT_PARSER_SRC_O	=	$(patsubst %.c,%.o, $(_FT_PARSER_SRC))
FT_PARSER_SRC_O		=	$(addprefix bin/,$(_FT_PARSER_SRC_O))

#Define FT_PRINT
_FT_PRINT_SRC		=	ft_putendl.c ft_putchar.c ft_putstr.c ft_putnbr.c\
						ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
						ft_putnbr_fd.c ft_puttab.c

FT_PRINT_SRC		=	$(addprefix ft_print/,$(_FT_PRINT_SRC))
_FT_PRINT_SRC_O		=	$(patsubst %.c,%.o, $(_FT_PRINT_SRC))
FT_PRINT_SRC_O		=	$(addprefix bin/,$(_FT_PRINT_SRC_O))

#Define FT_STR
_FT_STR_SRC			=	ft_striter.c ft_striteri.c ft_strdel.c ft_strclr.c\
						ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c\
						ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
						ft_strnew.c ft_strcat.c ft_strncat.c ft_strlcat.c \
						ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcmp.c\
						ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strstr.c\
						ft_strlen.c ft_strrev.c ft_strnstr.c ft_strfjoin.c\
						ft_strcut.c ft_str_to_tab.c

FT_STR_SRC			=	$(addprefix ft_str/,$(_FT_STR_SRC))
_FT_STR_SRC_O		=	$(patsubst %.c,%.o, $(_FT_STR_SRC))
FT_STR_SRC_O		=	$(addprefix bin/,$(_FT_STR_SRC_O))

#Define FT_UTILS
_FT_UTILS_SRC		=	ft_atoi.c ft_itoa.c ft_bzero.c ft_toupper.c ft_tolower.c\
						ft_nbrlen.c ft_nbrlen_base.c ft_wordlen.c ft_wordcount.c\
						ft_itoa_base.c ft_get_next_line.c ft_colors.c

FT_UTILS_SRC		=	$(addprefix ft_utils/,$(_FT_UTILS_SRC))
_FT_UTILS_SRC_O		=	$(patsubst %.c,%.o, $(_FT_UTILS_SRC))
FT_UTILS_SRC_O		=	$(addprefix bin/,$(_FT_UTILS_SRC_O))


#Define Global LIBFT files
LIBFT_SRC			=	$(FT_ARR_SRC) $(FT_IS_SRC) $(FT_LST_SRC) $(FT_MEM_SRC)\
						$(FT_PRINT_SRC) $(FT_STR_SRC) $(FT_UTILS_SRC) $(FT_MATRIX_SRC)\
						$(FT_PARSER_SRC)
_LIBFT_O_FILES		=	$(_FT_ARR_SRC_O) $(_FT_IS_SRC_O) $(_FT_LST_SRC_O)\
						$(_FT_MEM_SRC_O) $(_FT_PRINT_SRC_O) $(_FT_STR_SRC_O)\
						$(_FT_UTILS_SRC_O) $(_FT_MATRIX_SRC_O) $(_FT_PARSER_SRC_O)
LIBFT_O_FILES		=	$(FT_ARR_SRC_O) $(FT_IS_SRC_O) $(FT_LST_SRC_O)\
						$(FT_MEM_SRC_O) $(FT_PRINT_SRC_O) $(FT_STR_SRC_O)\
						$(FT_UTILS_SRC_O) $(FT_MATRIX_SRC_O) $(FT_PARSER_SRC_O)
CFLAGS				=	-Wall -Wextra -Werror -ggdb -g

all: $(NAME)

$(NAME):
	@mkdir bin
	@gcc -c $(CFLAGS) $(LIBFT_SRC)
	@ar rc $(NAME) $(_LIBFT_O_FILES)
	@ranlib $(NAME)
	@mv $(_LIBFT_O_FILES) bin/
	@echo "Library FT compilled"

clean:
	@rm -rf bin
	@echo "Clean all .o files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Clean all .o and .a"

re: fclean all
