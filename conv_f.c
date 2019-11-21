/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:04:09 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/21 17:10:59 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(t_conv_spec *conv_spec, t_bigint *whole,
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
	if (nbr.s.e == 0x7fff && bit_is_set(nbr.s.m, 63) && (nbr.s.m << 1) == 0)
		return (1);
	if ((nbr.s.e && !bit_is_set(nbr.s.m, 63)) || (nbr.s.e == 0x7fff &&
		bit_is_set(nbr.s.m, 63) && (nbr.s.m << 1)))
		return (2);
	if (nbr.s.e == 0 && nbr.s.m == 0)
	{
		if ((*whole = bigint_new(1)) == NULL)
			return (-1);
		if ((*frac = bigint_new(conv_spec->precision)) == NULL)
			return (-1);
		return (0);
	}
	if ((*whole = get_whole(nbr.s.m, nbr.s.e - 16383)) == NULL)
		return (-1);
	if ((*frac = get_fraction(nbr.s.m, nbr.s.e - 16383)) == NULL)
		return (-1);
	if (conv_spec->precision < (int)(*frac)->length)
		if (round_float(whole, frac, conv_spec->precision) == -1)
			return (-1);
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
	t_bigint *frac, int width)
{
	int res;
	int	w_len;
	int	f_len;

	w_len = whole == NULL ? 0 : whole->length;
	f_len = frac == NULL ? 0 : frac->length;
	res = POS_ZERO(width) + w_len + f_len;
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
	int				width;

	nbr.val = read_long_doule(ap, conv_spec->length);
	if ((is_nan_inf = get_float(nbr, conv_spec, &whole, &frac)) == -1)
		return (-1);
	width = get_width(conv_spec, whole, nbr.s.sign, is_nan_inf);
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar((is_nan_inf == 0) && (conv_spec->flags & FLAG_ZERO)
			? '0' : ' ', width);
	if ((conv_spec->flags & FLAG_PLUS) || nbr.s.sign)
		ft_putchar(nbr.s.sign ? '-' : '+');
	if (is_nan_inf)
		ft_putstr(is_nan_inf == 1 ? "inf" : "nan");
	else
		print_float(conv_spec, whole, frac);
	if ((conv_spec->flags & FLAG_MINUS))
		ft_putnchar(' ', width);
	return (get_printed_len(conv_spec, whole, frac, width));
}
