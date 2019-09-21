/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:03 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/21 22:21:37 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

int ft_printf(char *format, ...)
{
	va_list ap;
	int		pareser_ret;
	int		ret;

	ret = 0;
	pareser_ret = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			pareser_ret = parse_conversion(&format, &ap);
		if (pareser_ret == -1)
			break ;
		else
			ret += pareser_ret;
		ret += write(1, format++, 1);
	}
	va_end(ap);
	return (pareser_ret == -1 ? -1 : ret);
}