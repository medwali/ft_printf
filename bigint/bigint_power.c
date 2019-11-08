/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_power.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:33:39 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/08 14:57:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint	*bigint_power(unsigned int b, unsigned int exp)
{
	t_bigint	*res;
	t_bigint	*base;

	base = bigint_from_long(b);
	if (exp == 0)
		return bigint_from_long(1);
	else if (exp == 1)
		return base;
	res = bigint_from_long(1);
	while (exp > 1)
	{
		if (exp % 2)
		{
			res = bigint_mult(res,base);
			exp--;
		}
		exp /= 2;
		base = bigint_mult(base,base);
	}
	res = bigint_mult(res,base);
	return (res);
}
