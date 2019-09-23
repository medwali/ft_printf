/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 00:05:39 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/22 00:12:19 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_len(long long int n)
{
	int i;

	i = 1;
	while ((n = n / 10))
		i++;
	return (i);
}