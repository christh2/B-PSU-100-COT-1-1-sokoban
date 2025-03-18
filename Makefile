##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC	= gcc

SRC	= charge_map.c	\
	  help.c	\
	  move_to_p.c	\
	  main.c	\
	  strlen.c	\
	  get_p.c	\

OBJ	= $(SRC:.c=.o)

NAME	= my_sokoban

all	: $(NAME)


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(SRC) -lncurses -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
