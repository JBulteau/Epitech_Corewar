##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile our projects
##


LIB_DIR		=	$(realpath ./lib)

CC		=	gcc

all:
		$(MAKE) -C $(LIB_DIR)/my
		$(MAKE) -C asm/
		$(MAKE) -C corewar/
clean:
		$(MAKE) clean -C $(LIB_DIR)/my
		$(MAKE) clean -C asm/
		$(MAKE) clean -C corewar/

fclean:
		$(MAKE) fclean -C $(LIB_DIR)/my
		$(MAKE) fclean -C asm/
		$(MAKE) fclean -C corewar/

re:		fclean all

debug:
		$(MAKE) debug -C $(LIB_DIR)/my
		$(MAKE) debug -C asm/
		$(MAKE) debug -C corewar/
