/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:03 by mel-idri          #+#    #+#             */
/*   Updated: 2019/10/16 19:11:16 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stddef.h>

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
			if (parse_ret == -1)
				break;
			else
				ret += parse_ret;
		}
		else
		{
			if (*format == '{')
				ret += handle_color(&format);
			else if (*format == '\\' && *(format + 1) == '{')
			{
				ret += write(1, format, 2);
				format += 2;
			}
			else
				ret += write(1, format++, 1);
		}
	}
	va_end(ap);
	return (parse_ret == -1 ? -1 : ret);
}
// if
// \{red} -> {red}
// {red} -> red color
// \. -> \ -->