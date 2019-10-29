/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 08:23:38 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/03 03:37:22 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
# define BIGINT_H
# define IS_NULL(x) (x) == NULL

typedef struct
{
	char	*digits;
	int		length;
}			t_bigint;

t_bigint	*bigint_new(unsigned int size);
t_bigint	*bigint_mult(t_bigint *a, t_bigint *b);
t_bigint	*bigint_from_long(unsigned long n);
t_bigint	*bigint_power(unsigned int b, unsigned int e);

#endif