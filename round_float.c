/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:18:31 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/20 11:43:05 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	increment_float_part(t_bigint **whole, t_bigint **frac, int precision)
{
	unsigned int	frac_part_length;
	t_bigint		*added_number;

	if (precision == 0)
	{
		*whole = bigint_add(*whole, bigint_from_uint128(1));
		(*frac)->length = 0;
		return ;
	}
	frac_part_length = (*frac)->length;
	added_number = bigint_new((*frac)->length - precision + 1);
	added_number->digits[added_number->length - 1] = 1;
	*frac = bigint_add(*frac, added_number);
	if (frac_part_length < (*frac)->length)
	{
		*whole = bigint_add(*whole, bigint_from_uint128(1));
		*frac = bigint_new(1);
	}
}

void	round_float(t_bigint **whole, t_bigint **frac, int precision)
{
	int	i;
	int	index;

	index = (*frac)->length - precision - 1;
	if (index < 0)
		return ;
	if ((*frac)->digits[index] > 5)
		increment_float_part(whole, frac, precision);
	if ((*frac)->digits[index] == 5)
	{
		if ((precision == 0 && (*whole)->digits[0] % 2) ||
			(precision != 0 && (*frac)->digits[index + 1] % 2))
			increment_float_part(whole, frac, precision);
		else
		{
			i = index;
			while (--i >= 0)
				if ((*frac)->digits[i])
				{
					increment_float_part(whole, frac, precision);
					break ;
				}
		}
	}
}
