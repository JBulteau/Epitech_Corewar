/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** corewar
*/

#ifndef __COREWAR_H_
#define __COREWAR_H_

#include "op.h"

//NEW

typedef struct prog_s {
	struct prog_s *next;
	struct prog_s *next_f;
	struct prog_s *prev;
	int pc;
	int carry;
	int reg[REG_NUMBER];
	int cycle_wait;
	char *instr;
} prog_t;

typedef struct {
	int *live;
	int cycle_to_die;
	int current_cycle;
	prog_t *prog;
	char arena[MEM_SIZE];
} vm_t;

//OLD
typedef struct prog_name prog_name_t;

struct prog_name {
	prog_name_t *prev;
	char *name;
	int adress;
	int prog_nb;
	prog_name_t *next;
};

typedef struct args args_t;

struct args {
	int dump;
	prog_name_t *progs;
};

typedef struct {
	int p1;
	int p2;
	int p3;
	int p4;
	int i1;
	int i2;
	int i3;
	int i4;
} cheval_shop_t;

/* vm_struct.c */
vm_t *init_vm(int prog_num);


args_t *check_args(int ac, char **av);
args_t *check_dump(args_t *args, int ac, char **av, int nb_args);
args_t *check_flags(args_t *args, int ac, char **av);
args_t *check_prog_number(args_t *args, char *str);
args_t *check_adress(args_t *args, char *str);
args_t *check_prog(args_t *args, char *str);
void error(char *str, args_t *args);
int rev_endiannes(int nb);
void load_vm(args_t *args, int nb_progs);
//Ca compilait pas :/
//prog_info_t *load_program(prog_name_t *prog_name);
header_t *set_header(int fd, header_t *header);
char *get_name(int fd, char *prog_name, int *prog_size);
char *get_comment(int fd, char *comment, int *prog_size);

#define HELP		"USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...\n\nDESCRIPTION\n\t-dump nbr_cycle\tdumps the memory after the nbr_cycle execution (if the round isn’t\n\t\t\talready over) with the following format: 32 bytes/line in\n\t\t\thexadecimal (A0BCDEFE1DD3...)\n\t-n prog_number\tsets the next program’s number. By default, the first free number\n\t\t\tin the parameter order\n\t-a load_address\tsets the next program’s loading address. When no address is\n\t\t\tspecified, optimize the addresses so that the processes are as far\n\t\t\taway from each other as possible. The addresses are %i modulo.\n"
#define TOO_BIG_PROG	"Wrong program size in the header : Program is too big.\n"
#define DOUBLE_DUMP	"Double definition of option dump.\n"
#define	WRONG_FLAG	"Invalid option.\n"
#define NO_CHAMPION	"No champion specified.\n"
#define MISPLACED_DUMP	"-dump flag misplaced.\n"
#define NEG_DUMP	"-dump argument is invalid. Please enter a positive number.\n"
#define NO_DUMP		"No arguments to -dump\n"
#define NOT_EXEC	" is not an executable.\n"
#define WRONG_MAGIC_NB	"Wrong executable magic number.\n"
#define TOO_MANY_CHAMP	"The number of champion load is above the limit.\n"
#define INVALID_OFFSET	"-a argument is invalid. Enter a valid memory offset.\n"
#define NO_ADRESS	"-a argument is invalid. No address specified.\n"
#define INVALID_N_NB	"-n argument is invalid. Enter a number between 1 and 4.\n"
#define NO_PROG_NB	"-n argument is invalid. No prog_number specified.\n"
#define DOUBLE_NB	"-n argument is invalid. Double definition of prog_number.\n"

#endif
