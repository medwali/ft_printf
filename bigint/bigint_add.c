/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:23:37 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/21 16:05:43 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint		*bigint_add(t_bigint *a, t_bigint *b)
{
	unsigned int	i;
	unsigned int	res_len;
	t_bigint		*res;

	if (a == NULL || b == NULL)
		return (NULL);
	res_len = ft_max(a->length, b->length) + 1;
	if ((res = bigint_new(res_len)) == -1)
		return (NULL);
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
	i = 0;
	res->length -= res->digits[res->length - 1] == 0 ? 1 : 0;
	return (res);
}
