# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 21:20:45 by mel-idri          #+#    #+#              #
#    Updated: 2019/11/22 13:57:29 by ylagtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGsS = -Wall -Wextra -Werror

CC = gcc

SRC =	conv_di.c \
		conv_u.c \
		conv_o.c \
		conv_c.c \
		conv_s.c \
		conv_f.c \
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
			libft/ft_putunbr_base.o

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTOBJ) $(BIGINT_OBJ)
	ar rc $(NAME) $(OBJ) $(LIBFTOBJ) $(BIGINT_OBJ)

main: main.c $(NAME)
	gcc -o main main.c $(NAME)

clean:
	rm -f $(OBJ) $(LIBFTOBJ) $(BIGINT_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f conv_d_test
	rm -f conv_u_test
	rm -f conv_o_test
	rm -f conv_f_test
	rm -f main

re: fclean all

conv_di: $(NAME)
	gcc $(CFLAGS) -o conv_d_test tests/conv_di.test.c $(NAME)

conv_u: $(NAME)
	gcc $(CFLAGS) -o conv_u_test tests/conv_u.test.c $(NAME)

conv_o: $(NAME)
	gcc $(CFLAGS) -o conv_o_test tests/conv_o.test.c $(NAME)

conv_f: $(NAME)
	gcc $(CFLAGS) -o conv_f_test tests/conv_f.test.c $(NAME)

.PHONY: all fclean re clean