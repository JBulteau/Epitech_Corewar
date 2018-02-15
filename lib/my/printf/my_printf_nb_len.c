/*
** EPITECH PROJECT, 2017
** My_Printf
** File description:
** printf
*/

#include "my.h"

int long_long_len(long long n)
{
	int len = 0;

	if (n < 0) {
		len++;
		n *= -1;
	}
	while (n > 15) {
		n /= 16;
		len++;
	}
	return (len);
}

int unsigned_len(unsigned int n, char *base)
{
	int len = 0;
	int b_len = my_strlen(base);

	while (n >= (unsigned int){b_len}) {
		n /= b_len;
		len++;
	}
	return (len);
}

int int_len(int n)
{
	int len = 0;

	if (n < 0) {
		len++;
		n *= -1;
	}
	while (n > 9) {
		n /= 10;
		len++;
	}
	return (len);
}
