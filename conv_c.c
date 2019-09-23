/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:48:30 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/23 13:55:16 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_c(t_conv_spec *conv_spec, va_list *ap)
{
	char c;

	c = (char)va_arg(*ap, int);
	if (conv_spec->width && !(conv_spec->flags & FLAG_MINUS))
		ft_putnchar(' ', conv_spec->width - 1);
	write(1, &c, 1);
	if (conv_spec->width && conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', conv_spec->width - 1);
	return (conv_spec->width ? conv_spec->width : 1);
}