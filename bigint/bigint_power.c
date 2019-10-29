/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_power.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:33:39 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/03 03:53:43 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint	*bigint_power(unsigned int b, unsigned int e)
{
	t_bigint *res;
	t_bigint *base;

	base = bigint_from_long(b);
	if (e == 0)
		return bigint_from_long(1);
	else if (e == 1)
		return base;
	res = bigint_from_long(1);
	while (e > 1)
	{
		if (e % 2)
		{
			res = bigint_mult(res,base);
			--e;
		}
		e /= 2;
		base = bigint_mult(base,base);
	}
	res = bigint_mult(res,base);
	return (res);
}
