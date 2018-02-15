/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** corewar
*/

#ifndef __COREWAR_H_
#define __COREWAR_H_

#define HELP	"USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number] \
[-a load_address] prog_name] ...\n\nDESCRIPTION\n\t-dump nbr_cycle\tdumps \
the memory after the nbr_cycle execution (if the round isn’t\n\t\t\talready \
over) with the following format: 32 bytes/line in\n\t\t\thexadecimal \
(A0BCDEFE1DD3...)\n\t-n prog_number\tsets the next program’s number. By \
default, the first free number\n\t\t\tin the parameter order\n\t-a \
load_address\tsets the next program’s loading address. When no address is\
\n\t\t\tspecified, optimize the addresses so that the processes are as far\
\n\t\t\taway from each other as possible. The addresses are %i modulo.\n"

#endif