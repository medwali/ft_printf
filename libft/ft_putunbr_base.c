/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:47:04 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/25 04:20:45 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*g_lower_base = "0123456789abcdef";
static const char	*g_upper_base = "0123456789ABCDEF";

void				ft_putunbr_base(unsigned long long n, int base,
		int is_upper)
{
	if (n / base)
		ft_putunbr(n / base);
	ft_putchar(is_upper ? g_upper_base[n % base] : g_lower_base[n % base]);
}
