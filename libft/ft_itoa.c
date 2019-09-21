/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:08:01 by mel-idri          #+#    #+#             */
/*   Updated: 2019/04/10 19:29:39 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		digit_len(int n)
{
	int i;

	i = 1;
	while ((n = n / 10))
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	long	num;
	char	*res;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n >= 0 ? n : -n;
	if ((res = ft_strnew(digit_len(n) + (n < 0 ? 1 : 0))) == NULL)
		return (NULL);
	i = 0;
	res[i] = '0';
	while (num / 10 != 0 || num % 10 != 0)
	{
		res[i++] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		res[i] = '-';
	ft_strrev(res);
	return (res);
}
