/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:44:55 by ylagtab           #+#    #+#             */
/*   Updated: 2019/10/07 14:11:42 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int get_spaces_len(t_conv_spec *conv_spec, int nbr_len)
{
	int width;
	int precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset == 0 && (conv_spec->flags & FLAG_ZERO))
		return (0);
	return (width - ft_max(precision, nbr_len) -
					(conv_spec->flags & FLAG_PLUS));
}

static int get_zeros_len(t_conv_spec *conv_spec, int nbr_len)
{
	int width;
	int precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset)
		return (precision - nbr_len);
	if (conv_spec->flags & FLAG_ZERO)
		return (width - nbr_len - (conv_spec->flags & FLAG_PLUS));
	return (0);
}

static int get_printed_len(int nbr_len, int spaces, int zeros)
{
	spaces = spaces > 0 ? spaces : 0;
	zeros = zeros > 0 ? zeros : 0;
	return (spaces + zeros + nbr_len);
}

int conv_u(t_conv_spec *conv_spec, va_list *ap)
{
	unsigned long long unbr;
	int nbr_len;
	int spaces;
	int zeros;

	unbr = read_uint(ap, conv_spec->length);
	nbr_len = ft_nbrlen(unbr);
	if (unbr == 0 && conv_spec->is_pset == 1 && conv_spec->precision == 0)
		nbr_len = 0;
	spaces = get_spaces_len(conv_spec, nbr_len);
	zeros = get_zeros_len(conv_spec, nbr_len);
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar(' ', spaces);
	ft_putnchar('0', zeros);
	if (!(unbr == 0 && conv_spec->is_pset == 1 && conv_spec->precision == 0))
		ft_putunbr(unbr);
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', spaces);
	return (get_printed_len(nbr_len, spaces, zeros));
}