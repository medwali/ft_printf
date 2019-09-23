/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:01:11 by ylagtab           #+#    #+#             */
/*   Updated: 2019/09/22 23:32:24 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int main()
{
    t_conv_spec conv_spec;

    conv_spec.flags |= FLAG_ZERO | FLAG_SPACE;
    conv_spec.width.value = 10;
    conv_spec.precision.value = 11;
    conv_spec.precision.isset = 1;
    ft_printf("hello %+010d\n", 1337);
    ft_printf("hello %010d", 1337);
    // conv_d(&conv_spec, 1337);
}