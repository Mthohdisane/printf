#include "main.h"

/**
 * print_char - prints character
 * @list: list of parameters
 * Return: amount of characters printed
 */
int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_string - prints a string
 * @list: list of parameters
 * Return: Amount of characters printed
 */
int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}


/**
 *print_percent - function to print %
 *@list: unused
 *
 *Return: always 1
 */

int print_percent(__attribute__((unused))va_list list)
{
char c = '%';
_putchar(c);
return (1);
}


/**
 * print_integer - prints an integer
 * @list: integer to print
 *
 * Return: number of chars and digits printed
 */

int print_integer(va_list list)
{
int x[10];
int f, d, t, y, i;

t = va_arg(list, int);
i = 0;
d = 1000000000;
x[0] = t / d;
for (f = 1; f < 10; f++)
{
d /= 10;
x[f] = (t / d) % 10;
}
if (t < 0)
{
_putchar('-');
i++;
for (f = 0; f < 10; f++)
x[f] *= -1;
}
for (f = 0, y = 0; f < 10; f++)
{
y += x[f];
if (y != 0 || f == 9)
{
_putchar('0' + x[f]);
i++;
}
}
return (i);
}

/**
 *print_decimal - print a decimal
 *@list: decimal to print
 *
 *Return: number of characters and digits printed
 */

int print_decimal(va_list list)
{
int x[10];
int f, d, t, y, i;

t = va_arg(list, int);
i = 0;
d = 1000000000;
x[0] = t / d;
for (f = 1; f < 10; f++)
{
d /= 10;
x[f] = (t / d) % 10;
}
if (t < 0)
{
_putchar('-');
i++;
for (f = 0; f < 10; f++)
x[f] *= -1;
}
for (f = 0, y = 0; f < 10; f++)
{
y += x[f];
if (y != 0 || f == 9)
{
_putchar('0' + x[f]);
i++;
}
}
return (i);
}
