#include "main.h"
/**
 * _printf - receive the main string and all arguments
 * to print a formated string
 * @format: string containing all the desired characters
 * Return: the number of characters printed (without the null byte)
 */
int _printf(const char *format, ...)
{
	int printed_chars;

	convert_t f_list[BUFFSIZE] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_decimal},
		{"i", print_integer},
		{"x", _hex_l},
		{"X", _hex_u},
		{"p", _hex_l},
		{"S", print_string},
		{"r", print_r},
		{"R", rot_13},
		{"b", print_binary},
		{"u", print_unint},
		{"o", print_octal},
		{NULL, NULL},
	};
	va_list arg_list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(arg_list, format);
	/*call parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
