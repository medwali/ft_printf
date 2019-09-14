#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_ZERO  1U
# define FLAG_HASH  2U
# define FLAG_SPACE 4U
# define FLAG_PLUS  8U
# define FLAG_MINUS 16U
# define FLAG_QUOTE 32U
# define WIDTH 1
# define PRECISION 2
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

void (*const conv_functions[256])(t_conv_spec*,va_list*);

#endif