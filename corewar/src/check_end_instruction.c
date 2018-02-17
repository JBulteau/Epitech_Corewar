/*
** EPITECH PROJECT, 2018
** check_instru
** File description:
** corewar
*/

#include "my.h"
#include "op.h"
#include "corewar.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void check_end_instru(end_s *check_end)
{
	if (check_end->p1 > 0)
		check_end->p1 -= 1;
	if (check_end->p2 > 0)
		check_end->p2 -= 1;
	if (check_end->p3 > 0)
		check_end->p3 -= 1;
	if (check_end->p4 > 0)
		check_end->p4 -= 1;
	if (check_end->i1 != 0)
		check_end->p1 = op_tab[check_end->i1 - 1]->nbr_cycles;
	if (check_end->i2 != 0)
		check_end->p2 = op_tab[check_end->i1 - 1]->nbr_cycles;
	if (check_end->i3 != 0)
		check_end->p3 = op_tab[check_end->i1 - 1]->nbr_cycles;
	if (check_end->i4 != 0)
		check_end->p4 = op_tab[check_end->i1 - 1]->nbr_cycles;
}
