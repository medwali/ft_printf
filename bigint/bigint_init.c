/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:42:28 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/16 14:21:23 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint 	*bigint_new(unsigned int size)
{
	t_bigint	*bg_int;

	bg_int = (t_bigint *)ft_autoalloc(sizeof(t_bigint));
	bg_int->length = size;
	bg_int->digits = (char *)ft_autoalloc(size);
	return (bg_int);
}

t_bigint 	*bigint_from_long(unsigned long unbr)
{
	int			len;
	int			i;
	t_bigint	*bg_int;

	len = ft_nbrlen(unbr);
	bg_int = bigint_new(len);
	i = 0;
	while (i < len)
	{
		bg_int->digits[i] = unbr % 10;
		unbr /= 10;
		i++;
	}
	return (bg_int);
}
