/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:44:55 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/21 14:43:05 by ylagtab          ###   ########.fr       */
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

int			conv_o(t_conv_spec *conv_spec, va_list *ap)
{
	unsigned long long	unbr;
	int					nbr_len;
	int					spaces;
	int					zeros;

	unbr = read_uint(ap, conv_spec->length);
	nbr_len = unbr == 0 ? 0 : ft_nbrlen_base(unbr, 8);
	spaces = get_spaces_len(conv_spec, 1, nbr_len);
	zeros = get_zeros_len(conv_spec, 1, nbr_len);
	zeros += (conv_spec->flags & FLAG_HASH) ? 1 : 0;
	spaces -= (conv_spec->flags & FLAG_HASH) ? 1 : 0;
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar(' ', spaces);
	if (conv_spec->flags & FLAG_PLUS)
		ft_putchar('+');
	ft_putnchar('0', zeros);
	if (!(unbr == 0 && conv_spec->is_pset == 1 && conv_spec->precision == 0))
	{
		ft_putunbr_base(unbr, 8, 0);
		nbr_len = nbr_len == 0 ? 1 : nbr_len;
	}
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', spaces);
	return (get_printed_len(conv_spec, nbr_len, spaces, zeros));
}
