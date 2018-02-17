/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** Header file for ASM
*/

#ifndef __ASM__
#define __ASM__

/* Text messages */

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
	char *label;
	struct node_instruction_s *next;
} node_t;

/* endianness.c */
int rev_endiannes_int(int nb);
short rev_endiannes_short(short nb);

/* writing.c */
int write_exec(char *filename);
int write_header(int fd, char *name, char *comment);
int write_arg(int fd, in_struct_t op, int arg);
int write_special(int fd, in_struct_t op);
int write_op(int fd, in_struct_t op);

/* linked_list.c */
node_t *fill_linked_list(char *filename, int *error);
int check_buff(char **buffer, int *error, int fd, char *to_check);
void test_synt_name(char *name, int *error);
char *my_strcpy2(char *dest, char const *src);

/* clean_str.c */
char *clear_str(char *buffer);
void spaces_handle(int *a, char *result, int *i, char *buffer);
void init_clear_str(char *buffer, char **result);

#endif