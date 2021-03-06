/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:49:56 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/25 21:24:16 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		bigint_is_zero(t_bigint *bg_int)
{
	unsigned int i;

	if (bg_int == NULL)
		return (-1);
	i = 0;
	while (i < bg_int->length)
		if (bg_int->digits[i] != 0)
			return (0);
	return (1);
}

int		bigint_print(t_bigint *bg_int)
{
	int		len;
	int		ret;

	ret = 0;
	if (bg_int == NULL)
		return (0);
	len = bg_int->length - 1;
	while (len >= 0)
	{
		ret += ft_putchar(bg_int->digits[len] + 48);
		len--;
	}
	return (ret);
}
