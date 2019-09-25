/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:31:50 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/25 15:28:00 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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