/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:22:14 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/25 05:19:39 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long get_int(t_conv_spec *conv_spec, va_list *ap)
{
	long long ret;

	if (conv_spec->length == L)
		ret = va_arg(*ap, long);
	else if (conv_spec->length == LL)
		ret = va_arg(*ap, long long);
	else
		ret = va_arg(*ap, int);
	return (ret);
}

int conv_x(t_conv_spec *conv_spec, va_list *ap)
{	
	unsigned long long	hex_nbr;
	int					nbr_len;	
	int					spaces;
	int					zeros;

	hex_nbr = get_int(conv_spec, ap);
	if (conv_spec->is_pset && conv_spec->precision  == 0 && hex_nbr == 0)
		return (0);
	nbr_len = digit_len_base(hex_nbr,16);
	spaces = get_spaces_len(conv_spec, 
		conv_spec->flags & FLAG_HASH ? 2 : 0, nbr_len);
	zeros = get_zeros_len(conv_spec,
		conv_spec->flags & FLAG_HASH ? 2 : 0, nbr_len);
	(conv_spec->flags & FLAG_MINUS) == 0 ? ft_putnchar(' ', spaces) : 0;
	conv_spec->flags & FLAG_HASH ? write(1, "0x", 2) : 0;
	ft_putnchar('0', zeros);
	ft_putunbr_base(hex_nbr, 16, conv_spec->conv_char == 'X');
	conv_spec->flags & FLAG_MINUS ? ft_putnchar(' ', spaces) : 0;
	return (spaces + zeros + (conv_spec->flags & FLAG_HASH ? 2 : 0));
}