#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
#include "../libft/libft.h"

# define FLAG_ZERO  1U
# define FLAG_HASH  2U
# define FLAG_SPACE 4U
# define FLAG_PLUS  8U
# define FLAG_MINUS 16U
# define FLAG_QUOTE 32U
# define UNDETERMINED 0
# define SEQ_MODE 1
# define POS_MODE 2
# define IS_DIGIT(x) '0' <= x && x <= '9'

typedef enum {HH = 1, H, L, LL, CAPITAL_L}	t_length;
typedef struct
{
	int										param_index;
	unsigned int							flags;
	struct
	{
		int									param_index;
		int									is_param;
		int									value;
	}										width;
	struct
	{
		int									param_index;
		int									is_param;
		int									value;
	}										precision;
	t_length								length;
	char									conv_char;
}											t_conv_spec;

int parse_conversion(char **conv_str, va_list *ap);
int	is_in_str(int c, char *str);
int	conv_d(t_conv_spec *conv_spec, va_list *ap);
int ft_printf(char *format, ...);






















































int (*const conv_functions[256])(t_conv_spec*,va_list*);

#endif