##
## EPITECH PROJECT, 2017
## EvalExpr
## File description:
## Lib Makefile
##

NAME = my

SRCS =	concat.c \
	get_digits.c	\
	get_next_line.c	\
	indexof.c	\
	my_getnbr.c	\
	my_put.c	\
	my_strdup.c	\
	my_strcmp.c	\
	my_strlen.c	\
	my_putstr_octal.c\
	my_put_long_long.c\
	my_unsigned_base.c\
	my_putnbr_base.c\
	printf/my_printf.c\
	printf/my_printf_char.c\
	printf/my_printf_convert.c\
	printf/my_printf_display.c\
	printf/my_printf_flags.c\
	printf/my_printf_nb_len.c\
	printf/my_printf_nb.c\
	printf/my_printf_test_flags.c\

OBJS = $(SRCS:.c=.o)

INC = -I ../../include

CC = gcc

CFLAGS = $(INC) -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc lib$(NAME).a $(OBJS)
	cp lib$(NAME).a ..
clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f lib$(NAME).a
	rm -f ../lib$(NAME).a

re: fclean all

debug: CFLAGS += -g
debug: re