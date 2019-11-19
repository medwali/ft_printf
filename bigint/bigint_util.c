/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:49:56 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/19 10:00:12 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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