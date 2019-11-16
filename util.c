/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:31:50 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/08 21:40:57 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int is_in_str(int c, char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

void put_octal(unsigned long long decimal)
{
	if (decimal / 8)
		put_octal(decimal / 8);
	ft_putchar(decimal % 8 + '0');
}

void print_bits(unsigned long long nbr, int size)
{
	while (size--)
	{
		if (((nbr >> size) & 1) == 0)
			ft_putchar('0');
		else
			ft_putchar('1');
	}
}