/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_power.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:33:39 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/21 16:03:27 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint	*bigint_power(unsigned int b, unsigned int exp)
{
	t_bigint	*res;
	t_bigint	*base;

	if ((base = bigint_from_uint128(b)) == -1)
		return (NULL);
	if (exp <= 0)
		return (bigint_from_uint128(1));
	else if (exp == 1)
		return (base);
	if ((res = (bigint_from_uint128(1))) == -1)
		return (NULL);
	while (exp > 1)
	{
		if (exp % 2 && (exp-- || 1))
			if ((res = bigint_mult(res, base)) == -1)
				return (NULL);
		exp /= 2;
		if ((base = bigint_mult(base, base)) == -1)
			return (NULL);
	}
	if ((res = bigint_mult(res, base)) == -1)
		return (NULL);
	return (res);
}
