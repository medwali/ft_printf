/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:01:12 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/30 17:45:59 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int (*get_conv_function(int c))(t_conv_spec*, va_list*)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return (&conv_d);
	else if (c == 'c')
		return (&conv_c);
	else if (c == 's')
		return (&conv_s);
	else if (c == 'x' || c == 'X')
		return (&conv_x);
	else if (c == 'p')
		return (&conv_p);
	else
		return (NULL);
}