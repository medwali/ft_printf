/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percenatge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:54:40 by ylagtab           #+#    #+#             */
/*   Updated: 2019/10/07 14:12:41 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <unistd.h>

int conv_percenatge(t_conv_spec *conv_spec, va_list *ap)
{
  int spaces;
  int zeros;
  (void)ap;
  if (conv_spec->flags & FLAG_ZERO)
    zeros = conv_spec->width - 1;
  else
    spaces = conv_spec->width - 1;
  if ((conv_spec->flags & FLAG_MINUS) == 0)
    ft_putnchar(' ', spaces);
  write(1, "%", 1);
  if (conv_spec->flags & FLAG_MINUS)
    ft_putnchar(' ', spaces);
  return (conv_spec->width == 0 ? 1 : conv_spec->width);
}