#include <stdarg.h>

ft_printf(char *format, ...)
{
	va_list ap;
	char	*tmp;

	va_start(ap, format);
	while (*format)
		if (*format == '%')
			format = (tmp = parser(format, &ap)) ? tmp : format;
		else
			write(1, format++, 1);
}