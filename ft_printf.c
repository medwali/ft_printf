/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:03 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/20 22:53:34 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>


int ft_printf(char *format, ...)
{
	va_list ap;
	int parse_ret;
	int ret;

	ret = 0;
	parse_ret = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			parse_ret = parse_conversion(&format, &ap);
			continue ;
		}
		if (parse_ret == -1)
			break;
		else
			ret += write(1, format++, 1);
	}
	va_end(ap);
	return (parse_ret == -1 ? -1 : ret);
}
