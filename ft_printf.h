/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:05 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/02 23:11:44 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "bigint/bigint.h"
#include "libft/libft.h"


#include <stdarg.h>

#define FLAG_ZERO 1U
#define FLAG_HASH 2U
#define FLAG_SPACE 4U
#define FLAG_PLUS 8U
#define FLAG_MINUS 16U
#define FLAG_QUOTE 32U
#define IS_DIGIT(x) '0' <= x &&x <= '9'
#define ABS(number) number > 0 ? number : (-1) * number

#define BOLD "\e[1m"
#define DIM "\e[1m"
#define UNDERLINED "\e[4m"
#define BLINK "\e[5m"
#define INVERTED "\e[7m"

#define HIDDEN "\e[30m"
#define BLACK "\e[30m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"
#define LIGHT_GRAY "\e[37m"
#define DARK_GRAY "\e[90m"
#define LIGHT_RED "\e[91m"
#define LIGHT_GREEN "\e[92m"
#define LIGHT_YELLOW "\e[93m"
#define LIGHT_BLUE "\e[94m"
#define LIGHT_MAGENTA "\e[95m"
#define LIGHT_CYAN "\e[96m"

#define END "\e[0m"

typedef enum
{
	HH = 1,
	H,
	L,
	LL,
	CAPITAL_L
} t_length;
typedef struct
{
	unsigned int flags;
	int width;
	int is_pset;
	int precision;
	t_length length;
	char conv_char;
} t_conv_spec;

int parse_conversion(char **conv_str, va_list *ap);
int (*get_conv_function(int c))(t_conv_spec *, va_list *);
int is_in_str(int c, char *str);
int ft_printf(char *format, ...);
int conv_di(t_conv_spec *conv_spec, va_list *ap);
int conv_u(t_conv_spec *conv_spec, va_list *ap);
int conv_o(t_conv_spec *conv_spec, va_list *ap);
int conv_c(t_conv_spec *conv_spec, va_list *ap);
int conv_s(t_conv_spec *conv_spec, va_list *ap);
int conv_percenatge(t_conv_spec *conv_spec, va_list *ap);
long long read_int(va_list *ap, t_length len);
unsigned long long read_uint(va_list *ap, t_length len);
void put_octal(unsigned long long decimal);
int handle_color(char **format);

#endif
