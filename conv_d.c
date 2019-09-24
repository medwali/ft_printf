/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:01 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/24 21:53:52 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	get_spaces_len(t_conv_spec *conv_spec, int nbr, int nbr_len)
{
	int		width;
	int		precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset)
	  return (width - ft_max(precision, nbr_len) -
		(nbr < 0 || (conv_spec->flags & FLAG_PLUS)));
	if (conv_spec->flags | FLAG_ZERO)
		return (0);
	return (width - nbr_len - (nbr < 0 || (conv_spec->flags & FLAG_PLUS)));
}

static int	get_zeros_len(t_conv_spec *conv_spec, int nbr, int nbr_len)
{
	int		width;
	int		precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset)
	  return (precision - nbr_len);
	if (conv_spec->flags | FLAG_ZERO)
		return (width - nbr_len - (nbr < 0 || (conv_spec->flags & FLAG_PLUS)));
	return (0);
}

int			get_printed_len(unsigned int flags, int nbr, int nbr_len, int spaces, int zeros)
{
	spaces = spaces > 0 ? spaces : 0;
	zeros = zeros > 0 ? zeros : 0;
	return (spaces + zeros + nbr_len + (nbr > 0 || (flags & FLAG_PLUS)));
}

static int	read_nbr(t_length len, char conv_c, unsigned long long *unbr, va_list *ap)
{
	int nbr;

	if(conv_c == 'd' || conv_c == 'i')
	{
		if (len == L)
			nbr = va_arg(*ap, long);
		else if (len == LL)
			nbr = va_arg(*ap, long long);
		else if (len == H)
			nbr = (short)va_arg(*ap, int);
		else if (len == HH)
			nbr = (char)va_arg(*ap, int);
		else
			nbr = va_arg(*ap, int);
		*unbr = ABS(nbr);
		return (nbr < 0);
	}
	if (len == L)
		*unbr = va_arg(*ap, unsigned long);
	else if (len == LL)
		*unbr = va_arg(*ap, unsigned long long);
	else if (len == H)
		*unbr = va_arg(*ap, unsigned int);
	else if (len == HH)
		*unbr = va_arg(*ap, unsigned int);
	else
		*unbr = va_arg(*ap, int);
	return (0);
}

int		conv_d(t_conv_spec *conv_spec, va_list *ap)
{
	unsigned long long	unbr;
	int					_signed;
	int					nbr_len;
	int					spaces;
	int					zeros;

	_signed = read_nbr(conv_spec->length, conv_spec->conv_char, &unbr, ap);
	nbr_len = digit_len(unbr);
	spaces = get_spaces_len(conv_spec, unbr, nbr_len);
	zeros = get_zeros_len(conv_spec, unbr, nbr_len);
	if ((conv_spec->flags & FLAG_MINUS) == 0)
		ft_putnchar(' ', spaces);
	if ((conv_spec->flags & FLAG_PLUS) || _signed)
		ft_putchar(_signed ? '-' : '+');
	ft_putnchar('0', zeros);
	ft_putunbr(unbr);
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', spaces);
	return (get_printed_len(conv_spec->flags, unbr, nbr_len, spaces, zeros));
}