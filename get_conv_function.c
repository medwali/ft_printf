/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:01:12 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/08 15:33:24 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int (*get_conv_function(int c))(t_conv_spec *, va_list *)
{
	if (c == 'd' || c == 'i')
		return (&conv_di);
	if (c == 'u')
		return (&conv_u);
	if (c == 'o')
		return (&conv_o);
	if (c == 'c')
		return (&conv_c);
	if (c == 's')
		return (&conv_s);
	if (c == 'f')
		return (&conv_f);
	if (c == '%')
		return (&conv_percenatge);
	return (NULL);
}