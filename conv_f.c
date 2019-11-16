/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:04:09 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/16 15:00:23 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


static long double read_long_doule(va_list *ap, t_length len)
{
	if (len == L)
		return va_arg(*ap, long double);
	return (long double)va_arg(*ap, double);
}

// static int bit_at(unsigned nbr, int index)
// {
// 	return (((nbr >> index) & 1) == 1);
// }

// static	classify_ld(t_conv_spec *conv_spec, t_extended_db ext_db)
// {
// 	if (~(ext_db.ld_struct.exp) == 0 && bit_at(ext_db.ld_struct.mantissa, 63)
// 	 && ext_db.m.fraction == 0)
// 	{
// 		write(1, "inf", 3);
// 		return (0);
// 	}

// }

static t_bigint *get_int(unsigned long mantissa, int shift)
{
	t_bigint	*bg_int;

	if (shift < 0)
		return (bigint_new(1));
	mantissa = mantissa >> (shift < 64 ? 63 - shift : 0);
	bg_int = bigint_from_long(mantissa);
	return (bg_int);
}

int conv_f(t_conv_spec *conv_spec, va_list *ap)
{
	t_extended_db	ext_db;
	int				shift;
	// t_bigint		*whole;

	ext_db.ld = read_long_doule(ap, conv_spec->length);
	shift = ext_db.ld_struct.exp - 16383;
	// whole
	ft_printf("%s", shift);
	// get_int(ext_db.ld_struct.mantissa, shift);
	return (0);
}