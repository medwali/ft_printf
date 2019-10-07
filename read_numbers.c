/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:31:16 by ylagtab           #+#    #+#             */
/*   Updated: 2019/10/07 14:11:08 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long read_int(va_list *ap, t_length len)
{
	if (len == L)
		return va_arg(*ap, long);
	else if (len == LL)
		return va_arg(*ap, long long);
	else if (len == H)
		return (short)va_arg(*ap, int);
	else if (len == HH)
		return (char)va_arg(*ap, int);
	return va_arg(*ap, int);
}

unsigned long long read_uint(va_list *ap, t_length len)
{
	if (len == L)
		return va_arg(*ap, unsigned long);
	else if (len == LL)
		return va_arg(*ap, unsigned long long);
	else if (len == H)
		return (unsigned short)va_arg(*ap, unsigned int);
	else if (len == HH)
		return (unsigned char)va_arg(*ap, unsigned int);
	return va_arg(*ap, unsigned int);
}