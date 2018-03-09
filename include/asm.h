/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** Header file for ASM
*/

#ifndef __ASM__
#define __ASM__

#define ERR_EMPTY	"The file is empty."
#define USAGE		"USAGE\n\t./asm file_name[.s]\nDESCRIPTION\n\tfile_name\tfile in assembly language to be converted into file_name.cor, an\n\t\t\texecutable in the Virtual Machine.\n"
#define NO_NAME 	"No name specified."
#define NO_COMMENT 	"No comment specified."
#define ERR_SYNTAX	"Syntax error."
#define ERR_INV_INS 	"Invalid instruction."
#define ERR_INV_LAB 	"Invalid label name."
#define ERR_MUL_LAB	"Multiple definition of the same label."
#define ERR_INV_REG	"Invalid register number."
#define ERR_INV_ARG	"The argument given to the instruction is invalid."
#define ERR_TOOMANY_ARGS	"Too many arguments given to the instruction."
#define ERR_MANY_NAMES	"The name can only be defined once."
#define ERR_MANY_COMMENT	"The comment can only be defined once."
#define ERR_NAME_FIRSTLN	"The name of your program must be the first line."
#define ERR_TOOLONG_NAME	"The program name is too long."
#define ERR_COMM_AFTER_NAME	"The comment must be just after the name."
#define ERR_TOOLONG_COMM	"The comment is too long."
#define ERR_UNDEF_LAB	"Undefined label."
#define ERR_UNDEF_COMM	"No comment specified."
#define ERR_UNDEF_NAME	"No name specified."
#define FILE_NOTFOUND	"Error in function open: No such file or directory."

typedef struct {
	int op_code;
	int args_types;
	int args[4];
} in_struct_t;

typedef struct node_instruction_s {
	in_struct_t info;
	char *label[4];
	struct node_instruction_s *next;
	int address;
} node_t;

int rev_endiannes_int(int nb);
short rev_endiannes_short(short nb);

int write_header(int fd, char *name, char *comment, int size);
int write_arg(int fd, in_struct_t op, int arg);
int write_special(int fd, in_struct_t op, int arg);
int write_op(int fd, in_struct_t op);

node_t *fill_linked_list(char *filename, int *error);
int check_buff(char **buffer, int *error, int fd, char *to_check);
int test_synt_name(char *name, int *error);
int name_handling(node_t **all, int fd, char **buffer, int *error);

int fill_second_case(node_t **first, node_t **second, node_t **save, \
char **buffer);
int fill_first_case(node_t **first, node_t **second, node_t **save, \
char **buffer);
void fill_first_case_two(node_t **first, node_t **second);
void write_args_type(in_struct_t *op, int type);
void write_args_stru(in_struct_t *op, char *strarg, int type, int nb_arg);

char *clear_str(char *buffer);
void spaces_handle(int *a, char *result, int *i, char *buffer);
void init_clear_str(char *buffer, char **result);
char *get_fn(char *pathname);

int size(in_struct_t op);
int size_arg(int args);
int size_indexes(int arg);
int size_notype(int opcode);

int parsing(node_t *first, char **buffer, int fd);
int parsing_first_word(char **buffer, node_t **new, int *inc);
int parsing_instru(char **buffer, int *inc, node_t *first, node_t *new);

int check_args(int op_code, char *args, node_t *op);
int find_instru(char *str);
int check_label_chars(char **buffer, int inc);

int is_valid_arg(char *arg, node_t *op, int i);

node_t *init_node(void);

void free_linked_list(node_t *linked_list);
int write_exec(char *filename, node_t *entry);
int open_new_file(char *filename);

int replace_labels(node_t *entry);

#endif
