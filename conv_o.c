/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:44:55 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/23 17:37:44 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_printed_len(t_conv_spec *conv_spec, int nbr_len,
	int spaces, int zeros)
{
	spaces = spaces > 0 ? spaces : 0;
	zeros = zeros > 0 ? zeros : 0;
	return (spaces + zeros + nbr_len + (conv_spec->flags & FLAG_PLUS));
}

static int		get_spaces_len(t_conv_spec *conv_spec, int nbr_len)
{
	int width;
	int precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset == 0 && (conv_spec->flags & FLAG_ZERO))
		return (0);
	return (width - ft_max(precision, nbr_len) -
			(conv_spec->flags & FLAG_PLUS ? 1 : 0));
}

static int		get_zeros_len(t_conv_spec *conv_spec, int nbr_len)
{
	int width;
	int precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset)
		return (precision - nbr_len);
	if (conv_spec->flags & FLAG_ZERO)
		return (width - nbr_len - (conv_spec->flags & FLAG_PLUS ? 1 : 0));
	return (0);
}

int			conv_o(t_conv_spec *conv_spec, va_list *ap)
{
	unsigned long long	unbr;
	int					nbr_len;
	int					spaces;
	int					zeros;

	unbr = read_uint(ap, conv_spec->length);
	nbr_len = unbr == 0 ? 1 : ft_nbrlen_base(unbr, 8);
	spaces = get_spaces_len(conv_spec, nbr_len);
	zeros = get_zeros_len(conv_spec, nbr_len);
	spaces -= (conv_spec->flags & FLAG_HASH) && unbr && zeros < 0 ? 1 : 0;
	zeros = (conv_spec->flags & FLAG_HASH) && unbr && zeros <= 0 ? 1 : zeros;
	if ((unbr == 0 && conv_spec->is_pset == 1 && conv_spec->precision == 0))
	{
		spaces++;
		nbr_len = 0;
	}
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar(' ', spaces);
	if (conv_spec->flags & FLAG_PLUS)
		ft_putchar('+');
	ft_putnchar('0', zeros);
	if (!(unbr == 0 && conv_spec->is_pset == 1 && conv_spec->precision == 0))
		ft_putunbr_base(unbr, 8, 0);
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', spaces);
	return (get_printed_len(conv_spec, nbr_len, spaces, zeros));
}
