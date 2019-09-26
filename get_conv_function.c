/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:01:12 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/25 22:39:51 by mel-idri         ###   ########.fr       */
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
	else
		return (NULL);
}