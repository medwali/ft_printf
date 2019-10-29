/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:01:12 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/02 22:25:04 by mohamed          ###   ########.fr       */
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
	if (c == '%')
		return (&conv_percenatge);
	return (NULL);
}