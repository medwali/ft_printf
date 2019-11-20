/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:04:09 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/20 19:21:03 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_spaces_len(t_conv_spec *conv_spec, t_bigint *whole,
	int is_neg, int is_nan_inf)
{
	int width;
	int precision;
	int len;

	precision = conv_spec->precision;
	width = conv_spec->width;
	len = 3;
	if (is_nan_inf == 0)
		len = whole->length + precision + 1;
	return (width - len - (is_neg || (conv_spec->flags & FLAG_PLUS)));
}

static int	get_float(t_extended_db nbr, t_conv_spec *conv_spec,
	t_bigint **whole, t_bigint **frac)
{
	*whole = NULL;
	*frac = NULL;
	conv_spec->precision = conv_spec->is_pset ? conv_spec->precision : 6;
	if (~nbr.s.e == 0 && bit_is_set(nbr.s.m, 63) && (nbr.s.m << 1) == 0)
		return (1);
	if ((nbr.s.e && !bit_is_set(nbr.s.m, 63)) || (~nbr.s.e == 0 &&
		bit_is_set(nbr.s.m, 63) && (nbr.s.m << 1)))
		return (2);
	if (nbr.s.e == 0 && nbr.s.m == 0)
	{
		*whole = bigint_new(1);
		*frac = bigint_new(conv_spec->precision);
		return (0);
	}
	*whole = get_whole(nbr.s.m, nbr.s.e - 16383);
	*frac = get_fraction(nbr.s.m, nbr.s.e - 16383);
	if (conv_spec->precision < (int)(*frac)->length)
		round_float(whole, frac, conv_spec->precision);
	while ((int)(*frac)->length > conv_spec->precision)
	{
		(*frac)->length--;
		(*frac)->digits++;
	}
	return (0);
}

static void	print_float(t_conv_spec *conv_spec, t_bigint *whole, t_bigint *frac)
{
	bigint_print(whole);
	if (conv_spec->is_pset == 0 || conv_spec->precision != 0 ||
		(conv_spec->flags & FLAG_HASH))
		ft_putchar('.');
	bigint_print(frac);
}

static int	get_printed_len(t_conv_spec *conv_spec, t_bigint *whole,
	t_bigint *frac, int spaces)
{
	int res;

	res = POS_ZERO(spaces) + whole->length + frac->length;
	if (conv_spec->is_pset == 0 || conv_spec->precision != 0 ||
		(conv_spec->flags & FLAG_HASH))
		res += 1;
	return (res);
}

int			conv_f(t_conv_spec *conv_spec, va_list *ap)
{
	t_extended_db	nbr;
	t_bigint		*whole;
	t_bigint		*frac;
	int				is_nan_inf;
	int				spaces;

	nbr.val = read_long_doule(ap, conv_spec->length);
	is_nan_inf = get_float(nbr, conv_spec, &whole, &frac);
	spaces = get_spaces_len(conv_spec, whole, nbr.s.sign, is_nan_inf);
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar((conv_spec->flags & FLAG_ZERO) ? '0' : ' ', spaces);
	if ((conv_spec->flags & FLAG_PLUS) || nbr.s.sign)
		ft_putchar(nbr.s.sign ? '-' : '+');
	if (is_nan_inf)
		ft_putstr(is_nan_inf == 1 ? "inf" : "nan");
	else
		print_float(conv_spec, whole, frac);
	if ((conv_spec->flags & FLAG_MINUS))
		ft_putnchar(' ', spaces);
	return (get_printed_len(conv_spec, whole, frac, spaces));
}
