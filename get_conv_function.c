/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:01:12 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/23 06:04:19 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int (*get_conv_function(int c))(t_conv_spec*, va_list*)
{
	if (c == 'd' || c == 'i')
		return (&conv_d);
	else if (c == 'c')
		return (&conv_c);
	else if (c == 's')
		return (&conv_s);
	else
		return (NULL);
}