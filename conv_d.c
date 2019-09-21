/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:01 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/21 23:53:51 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdarg.h>
#include "ft_printf.h"

int	conv_d(t_conv_spec *conv_spec, va_list *ap)
{
	long long int	val;
	char			*s;
	int				i;

	if (conv_spec->width.is_param)
		conv_spec->width.value = va_arg(*ap, int);
	if (conv_spec->precision.is_param)
		conv_spec->precision.value = va_arg(*ap, int);
	if (conv_spec->length == L)
		val = va_arg(*ap, long int);
	else if (conv_spec->length == LL)
		val = va_arg(*ap, long long int);
	else if (conv_spec->length == H)
		val = (short)va_arg(*ap, int);
	else if (conv_spec->length == HH)
		val = (char)va_arg(*ap, int);
	else
		val = va_arg(*ap, int);
	if ((s = ft_itoa(val)) == NULL)
		return (-1);
	i = 0;
	while (s[i])
		write(1, s + i++, 1);
	return (i);
}