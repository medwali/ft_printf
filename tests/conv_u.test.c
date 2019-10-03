/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:07:20 by ylagtab           #+#    #+#             */
/*   Updated: 2019/10/03 11:56:17 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
int main()
{
	ft_printf("|");
	int g = ft_printf("%+u", 4294967295);
	ft_printf("|");
	ft_printf("%d", g);
	ft_printf("|\n");
	printf("|");
	int x = printf("%+u", 4294967295);
	printf("|");
	printf("%d", x);
	printf("|\n");
	// ft_printf("lu       : |%lu|\n", 133713371337);
	// ft_printf("+lu      : |%+lu|\n", 133713371337);
	// ft_printf("20lu     : |%20lu|\n", 133713371337);
	// ft_printf("-20lu    : |%-20lu|\n", 133713371337);
	// ft_printf("20.14lu  : |%20.14lu|\n", 133713371337);
	// ft_printf("-20.14lu : |%-20.14lu|\n", 133713371337);
	// ft_printf("+20.14lu : |%+.20lu|\n", 133713371337);
	// ft_printf("020lu    : |%020lu|\n", 133713371337);
	// ft_printf("020.14lu : |%020.14lu|\n", 133713371337);
	return (0);
}