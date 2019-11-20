/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:49:56 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/20 10:55:11 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		bigint_is_zero(t_bigint *bg_int)
{
	unsigned int i;

	i = 0;
	while (i < bg_int->length)
		if (bg_int->digits[i] != 0)
			return (0);
	return (1);
}

void	bigint_print(t_bigint *bg_int)
{
	int len;

	len = bg_int->length - 1;
	while (len >= 0)
	{
		ft_putchar(bg_int->digits[len] + 48);
		len--;
	}
}
