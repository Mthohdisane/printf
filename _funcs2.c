#include "main.h"


/**
 * rot_13 - convert ROT13 to text
 * @list: argument
 *
 * Return: number of characters to be print
 */

int rot_13(va_list list)
{
	char ch[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char chs[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	unsigned int i = 0, j = 0;
	int s;
	char *str;

	s = 0;
	str = va_arg(list, char *);
	if (str == NULL)
		str = "(NULL)";
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; ch[j] != '\0'; j++)
		{
			if (ch[j] == str[i])
			{
				_putchar(chs[j]);
				s++;
				break;
			}
		}
		if (ch[j] == '\0')
		{
			_putchar(str[i]);
			s++;
		}
	}
	return (s);
}

/**
 * print_octal - prints the octal representation of a decimal number
 * @list: argument
 *
 * Return: number of characters printed
 */

int print_octal(va_list list)
{
	int j = 0;
	unsigned int num = va_arg(list, unsigned int);
	int arr[sizeof(int) * 8 + 1];
	int i = 0;

	if (num < 8)
	{
		_putchar(num + '0');
		j++;
		return (j);
	}

	else
	{
		while (num > 8)
		{
			arr[i] = num % 8;
			num /= 8;
			i++;
		}

		if (num < 8)
			arr[i] = num;

		while (i >= 0)
		{
			_putchar(arr[i] + '0');
			j++;
			i--;
		}
	}
	return (j);
}


/**
 * print_unint - prints an unsigned int number
 * @list: argument
 *
 * Return: number of characters printed
 */

int print_unint(va_list list)
{
	int i = 0;
	unsigned int num = va_arg(list, unsigned int);
	int j = 1;

	while (num / j > 9)
	{
		j *= 10;
	}

	while (j > 0)
	{
		_putchar(num / j + '0');
		i++;
		num %= j;
		j /= 10;
	}
	return (i);
}



/**
 * binary_recursive - numbers in binary in recursive
 * @num: number to print
 * @len: lenght of digit to print
 *
 * Return: length on success, -1 if NULL
 */

int binary_recursive(unsigned int num, int len)
{
	if (num / 2)
		len = binary_recursive((num / 2), (len + 1));
	_putchar(num % 2 + '0');

	return (len);
}



/**
 * print_binary - convert unsigned int to binary
 * @list: int to convert
 *
 * Return: integer
 */

int print_binary(va_list list)
{
	int len = 0;

	unsigned int num = va_arg(list, unsigned int);

	len = binary_recursive(num, len) + 1;
	return (len);
}

