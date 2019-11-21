/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_whole.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:30:53 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/21 16:22:24 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bigint	*get_whole(unsigned long mantissa, int exp)
{
	t_bigint	*bg_int;
	__uint128_t	m;
	int			len;

	if (exp < 0)
		return (bigint_new(1));
	m = (__uint128_t)mantissa;
	if (exp < 64)
		m = m >> (63 - exp);
	else if (exp < 128)
		m = m << (exp - 63);
	else
		m = m << 64;
	if ((bg_int = bigint_from_uint128(m)) == NULL)
		return (-1);
	if (exp >= 128)
		if ((bg_int = bigint_mult(bg_int, bigint_power(2, exp - 127))) == NULL)
			return (-1);
	len = bg_int->length - 1;
	while (bg_int->digits[len] == 0)
		len--;
	bg_int->length = len + 1;
	return (bg_int);
}