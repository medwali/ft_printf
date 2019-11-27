/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percenatge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:54:40 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/27 18:38:12 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <unistd.h>

int	conv_percenatge(t_conv_spec *conv_spec)
{
	int spaces;
	int zeros;

	if (conv_spec->flags & FLAG_ZERO)
		zeros = conv_spec->width - 1;
	else
		spaces = conv_spec->width - 1;
	if ((conv_spec->flags & FLAG_MINUS) == 0)
	{
		if (conv_spec->flags & FLAG_ZERO)
			ft_putnchar('0', zeros);
		else
			ft_putnchar(' ', spaces);
	}
	ft_write_buff("%", 1);
	if (conv_spec->flags & FLAG_MINUS)
		ft_putnchar(' ', spaces);
	return (conv_spec->width == 0 ? 1 : conv_spec->width);
}
