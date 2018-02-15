/*
** EPITECH PROJECT, 2017
** My_Printf
** File description:
** printf
*/

#include "my.h"
#include "my_printf.h"

int test_str_flags(char *str, int len, char *flags, int count)
{
	if (is_in_str('-', flags) == 0) {
		count += str_padding(len, flags, ' ');
		count += my_putstr_octal(str);
	} else {
		count += my_putstr_octal(str);
		count += str_padding(len, flags, ' ');
	}
	return (count);
}

int test_long_long_flags(long long nb, int len, char *flags, int count)
{
	if ((is_in_str(' ', flags) == 1) && (nb >= 0))
		count += my_putchar(' ');
	if ((is_in_str('+', flags) == 1) && (nb >= 0))
		count +=  my_putchar('+');
	len += count + 1;
	count += my_putchar('0');
	count += my_putchar('x');
	if (is_in_str('0', flags) == 1) {
		if (nb < 0) {
			count += my_putchar('-');
			nb *= -1;
		}
		count += str_padding(len + 2, flags, '0');
	} else if (is_in_str('-', flags) == 0)
		count += str_padding(len + 2, flags, ' ');
	count += my_put_long_long(nb, 0);
	if (is_in_str('-', flags) == 1)
		count += str_padding(len + 2, flags, ' ');
	return (count);
}

int test_unsigned_flags(unsigned int nb, char *base, char *flags, int count)
{
	int len = unsigned_len(nb, base) + 1;

	if ((my_strlen(base) != 2) && (my_strlen(base) != 10)\
&& (is_in_str('#', flags) == 1)) {
		if (my_strlen(base) == 16) {
			count += my_putchar('0') + my_putchar(23 + base[10]);
			len += 2;
		} else {
			count += my_putchar('0');
			len++;
		}
	}
	if (is_in_str('0', flags) == 1)
		count += str_padding(len, flags, '0');
	else if (is_in_str('-', flags) == 0)
		count += str_padding(len, flags, ' ');
	count += my_unsigned_base(nb, base, 0);
	if (is_in_str('-', flags) == 1)
		count += str_padding(len, flags, ' ');
	return (count);
}

int test_int_flags(int nb, int len, char *flags, int count)
{
	if ((is_in_str(' ', flags) == 1) && (nb >= 0))
		count += my_putchar(' ');
	if ((is_in_str('+', flags) == 1) && (nb >= 0))
		count += my_putchar('+');
	len += count + 1;
	if (is_in_str('0', flags) == 1) {
		if (nb < 0) {
			count += my_putchar('-');
			nb *= -1;
		}
		count += str_padding(len, flags, '0');
	} else if (is_in_str('-', flags) == 0)
		count += str_padding(len, flags, ' ');
	count += my_put_nbr(nb);
	if (is_in_str('-', flags) == 1)
		count += str_padding(len, flags, ' ');
	return (count);
}
