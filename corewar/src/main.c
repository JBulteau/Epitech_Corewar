/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main file
*/

#include "my.h"

int main(int ac, char **av)
{
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
		my_printf(HELP);
	}
	return (0);
}
