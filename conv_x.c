/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:22:14 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/23 17:38:05 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static int	get_spaces_len(t_conv_spec *conv_spec, unsigned int unbr,
		unsigned int nbr_len)
{
	int width;
	int precision;
	int spaces;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset == 0 && (conv_spec->flags & FLAG_ZERO))
		return (0);
	spaces = width - ft_max(precision, nbr_len);
	if (unbr < 0 || conv_spec->flags & FLAG_PLUS)
		spaces--;
	if (conv_spec->flags & FLAG_HASH && unbr)
		spaces -= 2;
	return (pos_zero(spaces));
}	
*/

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

int			conv_x(t_conv_spec *conv_spec, va_list *ap)
{
	unsigned long long	hex_nbr;
	int					nbr_len;
	int					spaces;
	int					zeros;

	// get number
	hex_nbr = read_uint(ap, conv_spec->length);
	nbr_len = ft_nbrlen_base(hex_nbr, 16);
 	if (conv_spec->is_pset && conv_spec->precision == 0 && hex_nbr == 0)
		nbr_len = 0;
	// get len
	spaces = get_spaces_len(conv_spec, nbr_len);
	spaces -= conv_spec->flags & FLAG_HASH && hex_nbr ? 2 : 0;
	zeros = get_zeros_len(conv_spec, nbr_len);
	zeros -= conv_spec->flags & FLAG_HASH && hex_nbr &&
((conv_spec->flags & FLAG_ZERO) && conv_spec->precision < nbr_len) ? 2 : 0;
	// printing
	(conv_spec->flags & FLAG_MINUS) == 0 ? ft_putnchar(' ', spaces) : 0;
	if (conv_spec->flags & FLAG_HASH && hex_nbr != 0)
		write(1, (conv_spec->conv_char == 'x' ? "0x" : "0X"), 2);
	ft_putnchar('0', zeros);
	if (!(conv_spec->is_pset && conv_spec->precision == 0 && hex_nbr == 0))
		ft_putunbr_base(hex_nbr, 16, conv_spec->conv_char == 'X');
	conv_spec->flags & FLAG_MINUS ? ft_putnchar(' ', spaces) : 0;
	return (pos_zero(spaces) + pos_zero(zeros) + nbr_len +
		((conv_spec->flags & FLAG_HASH) && hex_nbr ? 2 : 0));
}
