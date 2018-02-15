/*
** EPITECH PROJECT, 2017
** asm.h
** File description:
** Header file for ASM
*/

#ifndef __ASM__
#define __ASM__

#define ERR_EMPTY "The file is empty."
#define USAGE "USAGE\n\t./asm file_name[.s]\nDESCRIPTION\n\tfile_name\tfile in assembly language to be converted into file_name.cor, an\n\t\t\texecutable in the Virtual Machine.\n"
#define NO_NAME "No name specified."
#define NO_COMMENT "No comment specified."
#define ERR_SYNTAX "Syntax error."
#define ERR_INV_INS "Invalid instruction."
#define ERR_INV_LAB "Invalid label name."
#define ERR_MUL_LAB "Multiple definition of the same label."
#define ERR_INV_REG "Invalid register number."
#define ERR_INV_ARG "The argument given to the instruction is invalid."
#define ERR_TOOMANY_ARGS "Too many arguments given to the instruction."
#define ERR_MANY_NAMES "The name can only be defined once."
#define ERR_MANY_COMMENT "The comment can only be defined once."
#define ERR_NAME_FIRSTLN "The name of your program must be the first line."
#define ERR_TOOLONG_NAME "The program name is too long."
#define ERR_COMM_AFTER_NAME "The comment must be just after the name."
#define ERR_TOOLONG_COMM "The comment is too long."
#define ERR_UNDEF_LAB "Undefined label."
#define ERR_UNDEF_COMM "No comment specified."
#define ERR_UNDEF_COMM "No name specified."

#endif