/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:06 by mel-idri          #+#    #+#             */
/*   Updated: 2019/09/21 23:09:17 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void	parse_flags(t_conv_spec *conv_spec,char **conv)
{
	while (1)
	{
		if (**conv == '0')
			conv_spec->flags |= FLAG_ZERO;
		else if (**conv == ' ')
			conv_spec->flags |= FLAG_SPACE;
		else if (**conv == '#')
			conv_spec->flags |= FLAG_HASH;
		else if (**conv == '+')
			conv_spec->flags |= FLAG_PLUS;
		else if (**conv == '-')
			conv_spec->flags |= FLAG_MINUS;
		else if (**conv == '\'')
			conv_spec->flags |= FLAG_QUOTE;
		else
			return ;
		(*conv)++;
	}
}

void	parse_width(t_conv_spec *conv_spec,char **conv)
{
		if ('1' <= **conv && **conv <= '9')
		{
			conv_spec->width.value = ft_atoi(*conv);
			while (IS_DIGIT(**conv))
				(*conv)++;
		}
		else if (**conv == '*' && IS_DIGIT(*((*conv) + 1)))
		{
			conv_spec->width.is_param = 1;
			while (IS_DIGIT(**conv))
				(*conv)++;
			if (**conv == '$')
				(*conv)++;
		}
		else if (**conv == '*')
		{
			conv_spec->width.is_param = 1;
			(*conv)++;
		}
}

void	parse_precision(t_conv_spec *conv_spec,char **conv)
{
		if (**conv == '.')
			(*conv)++;
		else
			return ;
		if ('0' <= **conv && **conv <= '9')
		{
			conv_spec->precision.value = ft_atoi(*conv);
			while (IS_DIGIT(**conv))
				(*conv)++;
		}
		else if (**conv == '*' && IS_DIGIT(*((*conv) + 1)))
		{
			conv_spec->precision.is_param = 1;
			while (IS_DIGIT(**conv))
				(*conv)++;
			if (**conv == '$')
				(*conv)++;
		}
		else if (**conv == '*')
		{
			conv_spec->precision.is_param = 1;
			(*conv)++;
		}
}

void	parse_length(t_conv_spec *conv_spec,char **conv)
{
	if (**conv == 'h' && *((*conv) + 1) == 'h' )
	{
		conv_spec->length = HH;
		(*conv) += 2;
	}
	else if (**conv == 'l' && *((*conv) + 1) == 'l' )
	{
		conv_spec->length = LL;
		(*conv) += 2;
	}
	else if (**conv == 'l')
	{
		conv_spec->length = L;
		(*conv)++;
	}
	else if (**conv == 'h')
	{
		conv_spec->length = H;
		(*conv)++;
	}
	else if (**conv == 'L')
	{
		conv_spec->length = CAPITAL_L;
		(*conv)++;
	}
}

int		parse_conversion(char **conv_str, va_list *ap)
{
	t_conv_spec	conv_spec;
	char		*c_str;

	c_str = *conv_str;
	ft_bzero(&conv_spec, sizeof(t_conv_spec));
	c_str++;
	parse_flags(&conv_spec, &c_str);
	parse_width(&conv_spec, &c_str);
	parse_precision(&conv_spec, &c_str);
	parse_length(&conv_spec, &c_str);
	if (is_in_str(*c_str, "cspdiouxXf%"))
	{
		conv_spec.conv_char = *c_str;
		*conv_str = c_str;
		return (get_conv_function(*(*conv_str)++)(&conv_spec, ap));
	}
	else
 		return (0);
}