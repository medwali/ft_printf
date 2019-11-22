/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:01 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/22 09:56:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_di(t_conv_spec *conv_spec, va_list *ap)
{
	long long	nbr;
	int			nbr_len;
	int			spaces;
	int			zeros;

	nbr = read_int(ap, conv_spec->length);
	nbr_len = ft_nbrlen(ABS(nbr));
	if (nbr == 0 && conv_spec->is_pset == 1 && conv_spec->precision == 0)
		nbr_len = 0;
	spaces = get_spaces_len(conv_spec, nbr, nbr_len);
	if ((conv_spec->flags & FLAG_SPACE) && nbr >= 0)
		spaces = (spaces <= 0) ? 1 : spaces;
	zeros = get_zeros_len(conv_spec, nbr, nbr_len);
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar(' ', spaces);
	if ((conv_spec->flags & FLAG_PLUS) || nbr < 0)
		ft_putchar(nbr < 0 ? '-' : '+');
	ft_putnchar('0', zeros);
	if (!(nbr == 0 && conv_spec->is_pset == 1 && conv_spec->precision == 0))
		ft_putunbr(ABS(nbr));
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', spaces);
	return (pos_zero(spaces) + pos_zero(zeros) + nbr_len +
			(nbr < 0 || (conv_spec->flags & FLAG_PLUS)));
}
