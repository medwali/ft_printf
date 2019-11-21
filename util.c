/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:31:50 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/21 14:43:55 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_in_str(int c, char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

void	print_bits(__uint128_t nbr, int size)
{
	while (size--)
	{
		if (((nbr >> size) & 1) == 0)
			ft_putchar('0');
		else
			ft_putchar('1');
	}
}

int		bit_is_set(unsigned long nbr, int index)
{
	return (((nbr >> index) & 1) == 1);
}

int		get_spaces_len(t_conv_spec *conv_spec, int nbr, int nbr_len)
{
	int width;
	int precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset == 0 && (conv_spec->flags & FLAG_ZERO))
		return (0);
	return (width - ft_max(precision, nbr_len) -
					(nbr < 0 || (conv_spec->flags & FLAG_PLUS)));
}

int		get_zeros_len(t_conv_spec *conv_spec, int nbr, int nbr_len)
{
	int width;
	int precision;

	precision = conv_spec->precision;
	width = conv_spec->width;
	if (conv_spec->is_pset)
		return (precision - nbr_len);
	if (conv_spec->flags & FLAG_ZERO)
		return (width - nbr_len - (nbr < 0 || (conv_spec->flags & FLAG_PLUS)));
	return (0);
}
