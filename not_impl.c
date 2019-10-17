/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_impl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:09:26 by ylagtab           #+#    #+#             */
/*   Updated: 2019/10/08 12:22:07 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void  not_implmented(t_conv_spec *conv_spec, va_list *ap)
{
  (void)ap;
  write(1, ">>|", 3);
  write(1, conv_spec->conv_char, 1);
  write(1, "not Implemented|<<", 18);
}