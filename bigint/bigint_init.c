/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:42:28 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/03 01:34:00 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_bigint	*bigint_new(unsigned int size)
{
	t_bigint	*bg_int;

	bg_int = (t_bigint*)ft_autoalloc(sizeof(t_bigint));
	bg_int->length = size;
	bg_int->digits = (char*)ft_autoalloc(bg_int->length);
	return (bg_int);
}

t_bigint	*bigint_from_long(unsigned long n)
{
	int			len;
	int			i;
	t_bigint	*new;

	len = ft_nbrlen(ABS(n));
	new = bigint_new(len);
	i = 0;
	while (i < new->length)
	{
		new->digits[i++] = n % 10;
		n /= 10;
	}
	return (new);
}