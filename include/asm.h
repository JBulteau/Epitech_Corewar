/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** Header file for ASM
*/

#ifndef __ASM__
#define __ASM__

/* Text messages */

/*-1*/#define ERR_EMPTY	"The file is empty."
/*-2*/#define USAGE		"USAGE\n\t./asm file_name[.s]\nDESCRIPTION\n\tfile_name\tfile in assembly language to be converted into file_name.cor, an\n\t\t\texecutable in the Virtual Machine.\n"
/*-3*/#define NO_NAME 	"No name specified."
/*-4*/#define NO_COMMENT 	"No comment specified."
/*-5*/#define ERR_SYNTAX	"Syntax error."
/*-6*/#define ERR_INV_INS 	"Invalid instruction."
/*-7*/#define ERR_INV_LAB 	"Invalid label name."
/*-8*/#define ERR_MUL_LAB	"Multiple definition of the same label."
/*-9*/#define ERR_INV_REG	"Invalid register number."
/*-10*/#define ERR_INV_ARG	"The argument given to the instruction is invalid."
/*-11*/#define ERR_TOOMANY_ARGS	"Too many arguments given to the instruction."
/*-12*/#define ERR_MANY_NAMES	"The name can only be defined once."
/*-13*/#define ERR_MANY_COMMENT	"The comment can only be defined once."
/*-14*/#define ERR_NAME_FIRSTLN	"The name of your program must be the first line."
/*-15*/#define ERR_TOOLONG_NAME	"The program name is too long."
/*-16*/#define ERR_COMM_AFTER_NAME	"The comment must be just after the name."
/*-17*/#define ERR_TOOLONG_COMM	"The comment is too long."
/*-18*/#define ERR_UNDEF_LAB	"Undefined label."
/*-19*/#define ERR_UNDEF_COMM	"No comment specified."
/*-20*/#define ERR_UNDEF_NAME	"No name specified."
/*-21*/#define FILE_NOTFOUND	"Error in function open: No such file or directory."

typedef struct {
	int op_code;
	int args_types;
	int args[4];
} in_struct_t;

typedef struct node_instruction_s {
	in_struct_t info;
	char *label[5];
	struct node_instruction_s *next;
} node_t;

/* endianness.c */
int rev_endiannes_int(int nb);
short rev_endiannes_short(short nb);

/* writing.c */
int write_exec(char *filename);
int write_header(int fd, char *name, char *comment, int size);
int write_arg(int fd, in_struct_t op, int arg);
int write_special(int fd, in_struct_t op, int arg);
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
char *get_fn(char *pathname);

/* size_ins.c */
int size(in_struct_t op);
int size_arg(int args);
int size_indexes(int arg);
int size_notype(int opcode);

/* fill_linked_list.c */
int parsing(node_t *first, char **buffer, int fd);
void write_args_type(in_struct_t *op, int type);
void write_args_stru(in_struct_t *op, char *strarg, int type, int nb_arg);

/* check.c */
int check_args(int op_code, char *args, in_struct_t *op);
int find_instru(char *str);
int check_label_chars(char **buffer, int inc);

/*check_arg_ins*/
int is_valid_arg(char *arg);

#endif
