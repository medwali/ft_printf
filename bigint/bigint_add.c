/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:23:37 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/08 14:45:17 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint	*bigint_add(t_bigint *a, t_bigint *b)
{
	int 		i;
	int 		res_len;
	t_bigint 	*res;

	res_len = ft_max(a->length, b->length) + 1;
	res = bigint_new(res_len);
	i = 0;
	while (i < res_len)
	{
		res->digits[i] += i < a->length ? a->digits[i] : 0;
		res->digits[i] += i < b->length ? b->digits[i] : 0;
		if (res->digits[i] > 9)
		{
			res->digits[i + 1]++;
			res->digits[i] %= 10;
		}
		i++;
	}
	return (res);
}
