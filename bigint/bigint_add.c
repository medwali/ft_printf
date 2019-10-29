/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:23:37 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/03 01:48:33 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint	*bigint_add(t_bigint *a, t_bigint *b)
{
	int			i;
	int			new_len;
	t_bigint	*res;

	new_len = ft_max(a->length, b->length) + 1;
	res = bigint_new(new_len);
	i = 0;
	while (i < new_len)
	{
		res->digits[i] += a->digits[i] + b->digits[i];
		if (res->digits[i] > 9)
			res->digits[i + 1]++;
	}
	return (res);
}