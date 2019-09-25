/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:01 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/25 19:21:01 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int get_spaces_len(t_conv_spec *conv_spec, int nbr, int nbr_len)
{
	int width;
	int precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset == 0 && (conv_spec->flags & FLAG_ZERO))
		return (0);
	return (width - ft_max(precision, nbr_len) -
			(nbr < 0 || (conv_spec->flags & FLAG_PLUS)));
}

static int get_zeros_len(t_conv_spec *conv_spec, int nbr, int nbr_len)
{
	int width;
	int precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset)
		return (precision - nbr_len);
	if (conv_spec->flags & FLAG_ZERO)
		return (width - nbr_len - (nbr < 0 || (conv_spec->flags & FLAG_PLUS)));
	return (0);
}

int get_printed_len(unsigned int flags, int nbr, int nbr_len, int spaces, int zeros)
{
	spaces = spaces > 0 ? spaces : 0;
	zeros = zeros > 0 ? zeros : 0;
	return (spaces + zeros + nbr_len + (nbr < 0 || (flags & FLAG_PLUS)));
}

int conv_di(t_conv_spec *conv_spec, va_list *ap)
{
	long long nbr;
	int nbr_len;
	int spaces;
	int zeros;

	nbr = read_int(ap, conv_spec->length);
	nbr_len = digit_len(ABS(nbr));
	spaces = get_spaces_len(conv_spec, nbr, nbr_len);
	zeros = get_zeros_len(conv_spec, nbr, nbr_len);
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar(' ', spaces);
	if ((conv_spec->flags & FLAG_PLUS) || nbr < 0)
		ft_putchar(nbr < 0 ? '-' : '+');
	ft_putnchar('0', zeros);
	ft_putunbr(ABS(nbr));
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', spaces);
	return (get_printed_len(conv_spec->flags, nbr, nbr_len, spaces, zeros));
}