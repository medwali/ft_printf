# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 21:20:45 by mel-idri          #+#    #+#              #
#    Updated: 2019/11/28 20:10:01 by ylagtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRC =	conv_di.c \
		conv_u.c \
		conv_o.c \
		conv_c.c \
		conv_s.c \
		conv_f.c \
		conv_f_helper.c \
		conv_percenatge.c \
		conv_x.c \
		conv_p.c \
		ft_printf.c \
		parser.c \
		util.c \
		apply_conv_function.c \
		read_numbers.c \
		get_whole.c \
		get_fraction.c \
		round_float.c

BIGINT_OBJ = bigint/bigint_add.o \
			bigint/bigint_mult.o \
			bigint/bigint_power.o \
			bigint/bigint_init.o \
			bigint/bigint_util.o

LIBFTOBJ =	libft/ft_autoalloc.o \
			libft/ft_nbrlen.o \
			libft/ft_nbrlen_base.o \
			libft/ft_atoi.o \
			libft/ft_bzero.o \
			libft/ft_isalnum.o \
			libft/ft_isalpha.o \
			libft/ft_isascii.o \
			libft/ft_isdigit.o \
			libft/ft_islower.o \
			libft/ft_isprint.o \
			libft/ft_isspace.o \
			libft/ft_isupper.o \
			libft/ft_itoa.o \
			libft/ft_lstadd.o \
			libft/ft_lstdel.o \
			libft/ft_lstdelone.o \
			libft/ft_lstiter.o \
			libft/ft_lstmap.o \
			libft/ft_lstnew.o \
			libft/ft_lstsearch.o \
			libft/ft_max.o \
			libft/ft_memalloc.o \
			libft/ft_memccpy.o \
			libft/ft_memchr.o \
			libft/ft_memcmp.o \
			libft/ft_memcpy.o \
			libft/ft_memdel.o \
			libft/ft_memmove.o \
			libft/ft_memset.o \
			libft/ft_putchar.o \
			libft/ft_putchar_fd.o \
			libft/ft_putendl.o \
			libft/ft_putendl_fd.o \
			libft/ft_putnbr.o \
			libft/ft_putnbr_fd.o \
			libft/ft_putnchar.o \
			libft/ft_putstr.o \
			libft/ft_putstr_fd.o \
			libft/ft_putunbr.o \
			libft/ft_strcat.o \
			libft/ft_strchr.o \
			libft/ft_strclr.o \
			libft/ft_strcmp.o \
			libft/ft_strcpy.o \
			libft/ft_strdel.o \
			libft/ft_strdup.o \
			libft/ft_strequ.o \
			libft/ft_strichr.o \
			libft/ft_striter.o \
			libft/ft_striteri.o \
			libft/ft_strjoin.o \
			libft/ft_strlcat.o \
			libft/ft_strlen.o \
			libft/ft_strmap.o \
			libft/ft_strmapi.o \
			libft/ft_strncat.o \
			libft/ft_strncmp.o \
			libft/ft_strncpy.o \
			libft/ft_strnequ.o \
			libft/ft_strnew.o \
			libft/ft_strnstr.o \
			libft/ft_strrchr.o \
			libft/ft_strrev.o \
			libft/ft_strsplit.o \
			libft/ft_strstr.o \
			libft/ft_strsub.o \
			libft/ft_strtrim.o \
			libft/ft_tolower.o \
			libft/ft_toupper.o \
			libft/ft_putunbr_base.o \
			libft/ft_write_buff.o

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTOBJ) $(BIGINT_OBJ)
	ar rc $(NAME) $(OBJ) $(LIBFTOBJ) $(BIGINT_OBJ)

clean:
	rm -f $(OBJ) $(LIBFTOBJ) $(BIGINT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean
