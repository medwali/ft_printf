/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:05:08 by mel-idri          #+#    #+#             */
/*   Updated: 2019/04/10 19:28:24 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** find `c` index in `s`, otherwise return NULL
*/

size_t	ft_strichr(const char *s, int c)
{
	size_t i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i])
		if (s[i] == (char)c)
			return (i);
		else
			i++;
	return (-1);
}
