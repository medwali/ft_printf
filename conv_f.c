/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:04:09 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/19 20:58:43 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_spaces_len(t_conv_spec *conv_spec, t_bigint *whole,
	int is_neg, int is_nan_inf)
{
	int width;
	int precision;
	int nbrlen;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if ((conv_spec->flags & FLAG_ZERO))
		return (0);
	nbrlen = 3;
	if (is_nan_inf == 0)
		nbrlen = whole->length + precision + 1;
	return (width - nbrlen - (is_neg || (conv_spec->flags & FLAG_PLUS)));
}

static char	*get_float(t_extended_db nbr, t_conv_spec *conv_spec,
	t_bigint **whole, t_bigint **frac)
{
	char			is_nan_inf;

	*whole = NULL;
	*frac = NULL;
	if (~nbr.s.e == 0 && bit_is_set(nbr.s.m, 63) && (nbr.s.m << 1) == 0)
		return (1);
	if ((nbr.s.e && !bit_is_set(nbr.s.m, 63)) || (~nbr.s.e == 0 &&
		bit_is_set(nbr.s.m, 63) && (nbr.s.m << 1)))
		return (2);
	(void)conv_spec;
	*whole = get_whole(nbr.s.m, nbr.s.e - 16383);
	*frac = get_fraction(nbr.s.m, nbr.s.e - 16383);

	return (0);
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
	if ((conv_spec->flags & FLAG_MINUS))
		ft_putnchar(' ', spaces);
	return (0);
}
