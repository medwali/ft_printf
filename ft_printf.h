/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:05 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/16 14:18:08 by ylagtab          ###   ########.fr       */
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
#define IS_DIGIT(x) '0' <= x && x <= '9'
#define ABS(number) number > 0 ? number : (-1) * number

typedef enum	s_length
{
	HH = 1,
	H,
	L,
	LL,
	CAPITAL_L
}				t_length;

typedef struct	s_conv_spec
{
	unsigned int	flags;
	int				width;
	int				is_pset;
	int				precision;
	t_length		length;
	char			conv_char;
}				t_conv_spec;

typedef union	s_extended_db
{
	long double	ld;
	struct		s_long_double
	{
		int64_t			mantissa : 64;
		unsigned int	exp : 15;
		unsigned int	sign : 1;
	}			ld_struct;
} 				t_extended_db;

int					parse_conversion(char **conv_str, va_list *ap);
int					(*get_conv_function(int c))(t_conv_spec *, va_list *);
int					is_in_str(int c, char *str);
int					ft_printf(char *format, ...);
int					conv_di(t_conv_spec *conv_spec, va_list *ap);
int					conv_u(t_conv_spec *conv_spec, va_list *ap);
int					conv_o(t_conv_spec *conv_spec, va_list *ap);
int					conv_c(t_conv_spec *conv_spec, va_list *ap);
int					conv_s(t_conv_spec *conv_spec, va_list *ap);
int					conv_percenatge(t_conv_spec *conv_spec, va_list *ap);
long long 			read_int(va_list *ap, t_length len);
unsigned long long	read_uint(va_list *ap, t_length len);
void				put_octal(unsigned long long decimal);
int					conv_f(t_conv_spec *conv_spec, va_list *ap);
void				print_bits(unsigned long long nbr, int size);


#endif
