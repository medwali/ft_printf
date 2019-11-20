/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:01:12 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/20 22:57:31 by mel-idri         ###   ########.fr       */
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
	if (c == 'x' || c == 'X')
		return (&conv_x);
	if (c == 'p')
		return (&conv_p);
	return (NULL);
}
