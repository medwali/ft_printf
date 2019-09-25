/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:01:12 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/25 19:17:54 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int (*get_conv_function(int c))(t_conv_spec *, va_list *)
{
	if (c == 'd' || c == 'i')
		return (&conv_di);
	if (c == 'u')
		return (&conv_u);
	if (c == 'c')
		return (&conv_c);
	if (c == 's')
		return (&conv_s);
	return (NULL);
}