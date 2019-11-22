/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:49:56 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/22 11:05:26 by ylagtab          ###   ########.fr       */
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

void	bigint_print(t_bigint *bg_int)
{
	char	*str;
	int		len;
	int		i;

	if (bg_int == NULL)
		return ;
	str = (char *)ft_memalloc(bg_int->length);
	len = bg_int->length - 1;
	i = 0;
	while (i <= len)
	{
		str[i] = bg_int->digits[len - i] + 48;
		i++;
	}
	write(1, str, len + 1);
	ft_strdel(&str);
}
