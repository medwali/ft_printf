/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:18:31 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/19 20:53:47 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	increment_float_part(t_bigint **whole, t_bigint **frac, int precision)
{
	int			frac_part_length;
	t_bigint	*added_number;

	if (precision == 0)
		*whole = bigint_add(*whole, bigint_from_long(1));
	else if (precision >= 0)
	{
		frac_part_length = (*frac)->length;
		added_number = bigint_new(precision);
		added_number->digits[precision - 1] = 1;
		*frac = bigint_add(*frac, added_number);
		if (frac_part_length < (*frac)->length)
		{
			*whole = bigint_add(*whole, bigint_from_long(1));
			*frac = bigint_new(1);
		}
	}
}

void	round_float(t_bigint **whole, t_bigint **frac, int precision)
{
	int	is_one_added;
	int	i;

	if ((*frac)->length <= precision)
		return ;
	if ((*frac)->digits[precision] > 5)
		is_one_added = precision == 0 ? 2 : 1;
	increment_float_part(whole, frac, precision);
	if ((*frac)->digits[precision] == 5)
		if (precision == 0 && (*whole)->digits[0] % 2)
			increment_float_part(whole, frac, precision);
		else if (precision != 0 && (*frac)->digits[precision - 1] % 2)
			increment_float_part(whole, frac, precision);
		else
		{
			i = precision;
			while (++i < (*frac)->length)
				if ((*frac)->digits[i])
				{
					increment_float_part(whole, frac, precision);
					break ;
				}
		}
}
