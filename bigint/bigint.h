/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 08:23:38 by mel-idri          #+#    #+#             */
/*   Updated: 2019/11/09 00:23:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
#define BIGINT_H
#define IS_NULL(x) (x == NULL)

typedef struct	s_bigint
{
	char		*digits;
	unsigned	length;
}				t_bigint;

t_bigint	*bigint_new(unsigned int size);
t_bigint	*bigint_add(t_bigint *a, t_bigint *b);
t_bigint	*bigint_mult(t_bigint *a, t_bigint *b);
t_bigint	*bigint_from_long(unsigned long unbr);
t_bigint	*bigint_power(unsigned int b, unsigned int exp);

#endif
