/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** corewar
*/

#ifndef __COREWAR_H_
#define __COREWAR_H_

#include "op.h"

typedef struct {
	int op_code;
	int arg_type;
	int args[4];
} in_struct_t;

typedef struct prog_s prog_t;

struct prog_s {
	prog_t *next;
	prog_t *next_f;
	prog_t *prev;
	int nb_prog;
	int pc;
	int carry;
	int reg[REG_NUMBER];
	int cycle_wait;
	int size;
	int start_adr;
	in_struct_t instr;
};

typedef struct {
	int *live;
	int cycle_to_die;
	int current_cycle;
	int dump;
	prog_t **prog;
	unsigned char arena[MEM_SIZE];
} vm_t;

typedef struct prog_name prog_name_t;

struct prog_name {
	prog_name_t *prev;
	char *name;
	int address;
	int prog_nb;
	int size;
	prog_name_t *next;
};

typedef struct args args_t;

struct args {
	int dump;
	prog_name_t *progs;
};

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
#define NO_address	"-a argument is invalid. No address specified.\n"
#define INVALID_N_NB	"-n argument is invalid. Enter a number between 1 and 4.\n"
#define NO_PROG_NB	"-n argument is invalid. No prog_number specified.\n"
#define DOUBLE_NB	"-n argument is invalid. Double definition of prog_number.\n"
#define FILE_NOT_FOUND	"corewar: %s: No such file\n"

void free_vm(vm_t *vm, args_t *args);
void help(int ac, char **av);
args_t *check_args(int ac, char **av);
void free_progs(prog_t *prog);

args_t *check_prog(args_t *args, char *str);
args_t *check_address(args_t *args, char *str);
args_t *check_prog_number(args_t *args, char *str);
args_t *check_flags(args_t *args, int ac, char **av, int i);
args_t *check_dump(args_t *args, int ac, char **av, int nb_args);

void disp_arena(vm_t *vm);
void disp_instruction(in_struct_t op);

int st(unsigned char *arena, prog_t *prog);
int add(unsigned char *arena, prog_t *prog);
int sub(unsigned char *arena, prog_t *prog);
int and(unsigned char *arena, prog_t *prog);
int or(unsigned char *arena, prog_t *prog);

int fork_exec(unsigned char *arena, prog_t *prog);
int lld(unsigned char *arena, prog_t *prog);
int lldi(unsigned char *arena, prog_t *prog);
int lfork(unsigned char *arena, prog_t *prog);
int aff(unsigned char *arena, prog_t *prog);

int xor(unsigned char *arena, prog_t *prog);
int zjmp(unsigned char *arena, prog_t *prog);
int ldi(unsigned char *arena, prog_t *prog);
int sti(unsigned char *arena, prog_t *prog);

int live(unsigned char *arena, prog_t *prog);
int ld(unsigned char *arena, prog_t *prog);

prog_name_t *fill_nb_prog(prog_name_t *prog);
int get_program_size(prog_name_t *prog);
args_t *fill_empty_args(args_t *args, int nb_prog);
prog_name_t *init_args_value(void);

void free_dead_prog(prog_t *to_kill);
prog_t *new_fork_case(prog_t *prog);
void init_prog_struct(prog_t *new);
prog_t *new_prog_case(int i, vm_t *vm);
int fill_struct_vm_prog(int nb_prog, vm_t *vm, args_t *args);

int rev_endiannes(int nb);

int load_n_arena(unsigned char *arena, int pos, int size);
void read_one_arg(unsigned char *arena, int pos, in_struct_t *op);
void load_args(unsigned char *arena, in_struct_t *op, int pos);
void load_index(unsigned char *arena, in_struct_t *op, int pos);
in_struct_t read_instru(unsigned char *arena, int pos);

int execute(vm_t *vm, prog_t *prog);
int scheduler_cycle(prog_t *current, vm_t *vm);
int scheduler(vm_t *vm);

static int size_arg(int args);
static int size_indexes(int args);
static int size_notype(int opcode);
int size(in_struct_t op);

void error(char *str, args_t *args);
args_t *init_args(int ac, char **av, int *nb_progs);
int count_alive(vm_t *vm);
void check_cycle(vm_t *vm);

vm_t *load_program_in_arena(vm_t *vm, prog_name_t *prog, int fd);
vm_t *get_program_info(vm_t *vm, prog_name_t *prog_name, int free_memory);
vm_t *init_arena(vm_t *vm, args_t *args, int nb_prog);
vm_t *init_vm(int prog_num, args_t *args);

#endif
