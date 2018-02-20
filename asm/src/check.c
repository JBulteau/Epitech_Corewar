/*
** EPITECH PROJECT, 2017
** check.c
** File description:
** Functions that check inputs
*/

#include "my.h"
#include "asm.h"
#include "op.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

//int check_args(int op_code, char *args)
//{
//	return (0);
//}

int find_instru(char *str)
{
	int i = -1;

	while(str[++i] != '\0' && str[i] != ' ');
	//str[i] = '\0';
	i = -1;
	while(op_tab[++i].mnemonique != 0 &&
	      strcmp(op_tab[i].mnemonique, str, -1) != 0);
	if (op_tab[i].mnemonique == 0)
		return (-1);
	else
		return (i + 1);
}
