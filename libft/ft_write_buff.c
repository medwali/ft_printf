/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:03:30 by ylagtab           #+#    #+#             */
/*   Updated: 2019/11/25 20:19:52 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	g_buffer[BUFF_SIZE];
static int	g_buff_index;

int			ft_write_buff(char *str, size_t size)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (i < size)
	{
		if (g_buff_index == BUFF_SIZE - 1)
			ft_flush_buff();
		g_buffer[g_buff_index] = str[i];
		i++;
		g_buff_index++;
	}
	return (size);
}

void		ft_flush_buff(void)
{
	write(1, g_buffer, g_buff_index + 1);
	g_buff_index = 0;
}
