/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:59:15 by ylagtab           #+#    #+#             */
/*   Updated: 2019/10/16 19:10:36 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BOLD "\e[1m"
#define DIM "\e[1m"
#define UNDERLINED "\e[4m"
#define BLINK "\e[5m"
#define INVERTED "\e[7m"
#define HIDDEN "\e[30m"
#define BLACK "\e[30m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"
#define LIGHT_GRAY "\e[37m"
#define DARK_GRAY "\e[90m"
#define LIGHT_RED "\e[91m"
#define LIGHT_GREEN "\e[92m"
#define LIGHT_YELLOW "\e[93m"
#define LIGHT_BLUE "\e[94m"
#define LIGHT_MAGENTA "\e[95m"
#define LIGHT_CYAN "\e[96m"
#include "ft_printf.h"

int handle_color(char **format)
{
    if (ft_strncmp(*format, "{bold}", 6) == 0)
        write(1, BOLD, 6);
    if (ft_strncmp(*format, "{dim}", 5) == 0)
        write(1, DIM, 6);
    if (ft_strncmp(*format, "{underlined}", 12) == 0)
        write(1, UNDERLINED, 6);
    if (ft_strncmp(*format, "{blink}", 7) == 0)
        write(1, BLINK, 6);
    if (ft_strncmp(*format, "{inverted}", 10) == 0)
        write(1, INVERTED, 6);
    if (ft_strncmp(*format, "{hidden}", 8) == 0)
        write(1, HIDDEN, 6);
    if (ft_strncmp(*format, "{black}", 7) == 0)
        write(1, BLACK, 6);
    if (ft_strncmp(*format, "{red}", 5) == 0)
        write(1, RED, 6);
    if (ft_strncmp(*format, "{green}", 7) == 0)
        write(1, GREEN, 6);
    if (ft_strncmp(*format, "{yellow}", 8) == 0)
        write(1, YELLOW, 6);
    if (ft_strncmp(*format, "{blue}", 6) == 0)
        write(1, BLUE, 6);
    if (ft_strncmp(*format, "{magenta}", 9) == 0)
        write(1, MAGENTA, 6);
    if (ft_strncmp(*format, "{cyan}", 6) == 0)
        write(1, CYAN, 6);
    if (ft_strncmp(*format, "{light_gray}", 12) == 0)
        write(1, LIGHT_GRAY, 6);
    if (ft_strncmp(*format, "{dark_grey}", 11) == 0)
        write(1, DARK_GRAY, 6);
    if (ft_strncmp(*format, "{light_red}", 11) == 0)
        write(1, LIGHT_RED, 6);
    if (ft_strncmp(*format, "{light_green}", 13) == 0)
        write(1, LIGHT_GREEN, 6);
    if (ft_strncmp(*format, "{light_yellow}", 14) == 0)
        write(1, LIGHT_YELLOW, 6);
    if (ft_strncmp(*format, "{light_blue}", 12) == 0)
        write(1, LIGHT_BLUE, 6);
    if (ft_strncmp(*format, "{light_magenta}", 13) == 0)
        write(1, LIGHT_MAGENTA, 6);
    if (ft_strncmp(*format, "{light_cyan}", 12) == 0)
        write(1, LIGHT_CYAN, 6);
}
