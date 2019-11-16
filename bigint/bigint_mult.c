/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:10:42 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/09 00:25:54 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint	*bigint_mult(t_bigint *a, t_bigint *b)
{
	t_bigint	*res;
	unsigned int			i;
	unsigned int			j;

	res = bigint_new(a->length + b->length);
	i = 0;
	while (i < b->length)
	{
		j = 0;
		while (j < a->length)
		{
			res->digits[i + j] += b->digits[i] * a->digits[j];
			res->digits[i + j + 1] += res->digits[i + j] / 10;
			res->digits[i + j] %= 10;
			j++;
		}
		i++;
	}
	res->length -= res->digits[res->length - 1] == 0 ? 1 : 0;
	return (res);
}