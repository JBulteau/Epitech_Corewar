/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main file
*/

#include "my.h"
#include "asm.h"

int main(int ac, char **av)
{
	if (ac == 1)
		my_putstr(USAGE);
	return (0);
}