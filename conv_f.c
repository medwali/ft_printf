/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:04:09 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/25 20:16:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(t_conv_spec *conv_spec, t_bigint *whole,
	int is_neg, int is_nan_inf)
{
	int width;
	int precision;
	int len;
	int is_flag_hash;

	precision = conv_spec->precision;
	width = conv_spec->width;
	is_flag_hash = conv_spec->flags & FLAG_HASH ? 1 : 0;
	len = 3;
	if (is_nan_inf == FLOAT)
		len = whole->length + precision + is_flag_hash;
	width = width - len - (is_neg || (conv_spec->flags &
			(FLAG_PLUS | FLAG_SPACE)));
	return (width > 0 ? width : 0);
}

static int	fill_float_parts(t_extended_dbl ldbl, t_conv_spec *conv_spec,
	t_bigint **whole, t_bigint **frac)
{
	int float_type;

	*whole = NULL;
	*frac = NULL;
	conv_spec->precision = conv_spec->is_pset ? conv_spec->precision : 6;
	if ((float_type = check_float_type(ldbl, conv_spec, whole, frac))
			!= FLOAT)
		return (float_type);
	if ((*whole = get_whole(ldbl.s.m, ldbl.s.e - 16383)) == NULL)
		return (-1);
	if ((*frac = get_fraction(ldbl.s.m, ldbl.s.e - 16383)) == NULL)
		return (-1);
	if (conv_spec->precision < (int)(*frac)->length)
		if (round_float(whole, frac, conv_spec->precision) == -1)
			return (-1);
	while ((int)(*frac)->length > conv_spec->precision)
	{
		(*frac)->length--;
		(*frac)->digits++;
	}
	return (FLOAT);
}

static void	print_float(t_conv_spec *conv_spec, t_bigint *whole, t_bigint *frac)
{
	bigint_print(whole);
	if (conv_spec->is_pset == 0 || conv_spec->precision != 0 ||
		(conv_spec->flags & FLAG_HASH))
		ft_putchar('.');
	bigint_print(frac);
	ft_putnchar('0', conv_spec->precision - frac->length);
}

static int	get_printed_len(t_conv_spec *conv_spec, t_bigint *whole,
	t_bigint *frac, int width)
{
	int res;
	int	w_len;
	int	f_len;

	w_len = whole == NULL ? 0 : whole->length;
	f_len = frac == NULL ? 0 : frac->length;
	res = width + w_len + f_len;
	if (conv_spec->is_pset == 0 || conv_spec->precision != 0 ||
		(conv_spec->flags & FLAG_HASH))
		res += 1;
	if (conv_spec->precision - frac->length > 0) 
		res += conv_spec->precision - frac->length;
	return (res);
}

int			conv_f(t_conv_spec *conv_spec, va_list *ap)
{
	t_extended_dbl	ldbl;
	t_bigint		*whole;
	t_bigint		*frac;
	int				float_type;
	int				width;
	int				ret;

	ret = 0;
	ldbl.val = read_long_double(ap, conv_spec->length);
	if ((float_type = fill_float_parts(ldbl, conv_spec, &whole, &frac)) == -1)
		return (-1);
	width = get_width(conv_spec, whole, ldbl.s.sign, float_type);
	if ((!(conv_spec->flags & FLAG_MINUS) && !(conv_spec->flags & FLAG_ZERO)))
		ret += ft_putnchar(' ', width);
	print_float_prefix(conv_spec, ldbl.s.sign);
	if (float_type == 0 && (conv_spec->flags & FLAG_ZERO))
		ret += ft_putnchar('0', width);
	if (float_type == INF || float_type == NAN)
		ret += ft_putstr(float_type == INF ? "inf" : "nan");
	else
		print_float(conv_spec, whole, frac);
	if ((conv_spec->flags & FLAG_MINUS))
		ret += ft_putnchar(' ', width);
	return (get_printed_len(conv_spec, whole, frac, width));
}
