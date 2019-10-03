/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:07:20 by ylagtab           #+#    #+#             */
/*   Updated: 2019/10/03 11:26:41 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
int main()
{
	// ft_printf("|");
	// int b = ft_printf("%ld", -2147483649);
	// ft_printf("|");
	// ft_printf("%d", b);
	// ft_printf("|\n");

	// ft_printf("|");
	// int c = ft_printf("%lld", 9223372036854775807);
	// ft_printf("|");
	// ft_printf("%d", c);
	// ft_printf("|\n");

	// ft_printf("|");
	// int d = ft_printf("%lld", -9223372036854775808);
	// ft_printf("|");
	// ft_printf("%d", d);
	// ft_printf("|\n");

	ft_printf("|");
	int e = ft_printf("@moulitest: %.d %.0d", 0, 0);
	ft_printf("|");
	ft_printf("%d", e);
	ft_printf("|\n");
	printf("|");
	int x = printf("@moulitest: %.d %.0d", 0, 0);
	printf("|");
	printf("%d", x);
	printf("|\n");
	// ft_printf("|");
	// int f = ft_printf("@moulitest: %5.d %5.0d", 0, 0);
	// ft_printf("|");
	// ft_printf("%d", f);
	// ft_printf("|\n");

	// ft_printf("|");
	// int g = ft_printf("%+u", 4294967295);
	// ft_printf("|");
	// ft_printf("%d", g);
	// ft_printf("|\n");

	return (0);
}