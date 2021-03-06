/*
** EPITECH PROJECT, 2017
** endianness.c
** File description:
** Endianness functions
*/

#include "my.h"

int check_endianness(void)
{
	if (1 >> sizeof(int))
		return (0);
	else
		return (1);
}

int rev_endiannes_int(int nb)
{
	int res = 0;

	for (int i = 0; i < 4; i++) {
		if (res)
			res = res << 8;
		res += nb >> (8 * i) & (0xff);
	}
	return (res);
}

short rev_endiannes_short(short nb)
{
	short res = 0;

	for (int i = 0; i < 2; i++) {
		if (res)
			res = res << 8;
		res += nb >> (8 * i) & (0xff);
	}
	return (res);
}