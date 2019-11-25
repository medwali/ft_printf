/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:10:32 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/25 21:07:39 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_float_type(t_extended_dbl ldbl, t_conv_spec *conv_spec,
		t_bigint **whole, t_bigint **frac)
{
	if (ldbl.s.e == 0x7fff && bit_is_set(ldbl.s.m, 63) && (ldbl.s.m << 1) == 0)
		return (INF);
	if ((ldbl.s.e && !bit_is_set(ldbl.s.m, 63)) || (ldbl.s.e == 0x7fff &&
		bit_is_set(ldbl.s.m, 63) && (ldbl.s.m << 1)))
		return (NAN);
	if (ldbl.s.e == 0 && ldbl.s.m == 0)
	{
		if ((*whole = bigint_new(1)) == NULL)
			return (-1);
		if ((*frac = bigint_new(conv_spec->precision)) == NULL)
			return (-1);
		return (ZERO);
	}
	return (FLOAT);
}

int	print_float_prefix(t_conv_spec *conv_spec, int float_sign)
{
	int ret;

	ret = 0;
	if ((conv_spec->flags & FLAG_PLUS) || float_sign)
		ret = ft_putchar(float_sign ? '-' : '+');
	else if (conv_spec->flags & FLAG_SPACE)
		ret = ft_putchar(' ');
	return (ret);
}