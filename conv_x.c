/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:22:14 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/22 16:54:17 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_x(t_conv_spec *conv_spec, va_list *ap)
{
	unsigned long long	hex_nbr;
	int					nbr_len;
	int					spaces;
	int					zeros;
	char				prefix[2];

	hex_nbr = read_uint(ap, conv_spec->length);
	if (conv_spec->is_pset && conv_spec->precision == 0 && hex_nbr == 0)
		return (0);
	nbr_len = ft_nbrlen_base(hex_nbr, 16);
	spaces = get_spaces_len(conv_spec, 1, nbr_len);
	spaces -= conv_spec->flags & FLAG_HASH && hex_nbr ? 2 : 0;
	zeros = get_zeros_len(conv_spec, 1, nbr_len);
	zeros -= conv_spec->flags & FLAG_HASH && hex_nbr &&
		((conv_spec->flags & FLAG_ZERO) && conv_spec->precision < nbr_len ) ? 2 : 0;
	(conv_spec->flags & FLAG_MINUS) == 0 ? ft_putnchar(' ', spaces) : 0;
	prefix[0] = '0';
	prefix[1] = conv_spec->conv_char;
	if (conv_spec->flags & FLAG_HASH && hex_nbr != 0)
		write(1, prefix, 2);
	ft_putnchar('0', zeros);
	ft_putunbr_base(hex_nbr, 16, conv_spec->conv_char == 'X');
	conv_spec->flags & FLAG_MINUS ? ft_putnchar(' ', spaces) : 0;
	return (pos_zero(spaces) + pos_zero(zeros) + nbr_len +
		((conv_spec->flags & FLAG_HASH) && hex_nbr ? 2 : 0));
}
