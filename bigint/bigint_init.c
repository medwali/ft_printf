/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:42:28 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/21 17:00:09 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint	*bigint_new(unsigned int size)
{
	t_bigint	*bg_int;

	if ((bg_int = (t_bigint *)ft_autoalloc(sizeof(t_bigint))) == NULL)
		return (NULL);
	bg_int->length = size;
	if ((bg_int->digits = (char *)ft_autoalloc(size)) == NULL)
		return (NULL);
	return (bg_int);
}

t_bigint	*bigint_from_uint128(__uint128_t unbr)
{
	int			len;
	int			i;
	t_bigint	*bg_int;

	len = ft_nbrlen(unbr);
	if ((bg_int = bigint_new(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		bg_int->digits[i] = unbr % 10;
		unbr /= 10;
		i++;
	}
	return (bg_int);
}
