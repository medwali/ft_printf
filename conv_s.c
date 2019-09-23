/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 00:12:42 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/23 05:45:20 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_s(t_conv_spec *conv_spec, va_list *ap)
{
	int str_len;
	char *str;

	str = va_arg(*ap, char*);
	str_len = ft_strlen(str);
	str_len = conv_spec->is_pset && conv_spec->precision < str_len ?
		conv_spec->precision : str_len;
	if (conv_spec->width && !(conv_spec->flags & FLAG_MINUS))
		ft_putnchar(' ',conv_spec->width - str_len);
	write(1, str, str_len);
	if (conv_spec->width && conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ',conv_spec->width - str_len);
	return(0);
}