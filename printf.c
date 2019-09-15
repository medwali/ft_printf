#include <stdarg.h>
#include <stdlib.h>

ft_printf(char *format, ...)
{
	va_list ap;
	int		pareser_ret;
	int		ret;

	ret = 0;
	pareser_ret = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			pareser_ret = parser(&format, &ap);
		if (pareser_ret == -1)
			break ;
		else
			ret += pareser_ret;
		ret += write(1, format++, 1);
	}
	va_end(ap);
	return (pareser_ret == -1 ? -1 : ret);
}