##
## EPITECH PROJECT, 2024
## tek-workshop-makefiles
## File description:
## Makefile
##

SRC = my_print_plus.c \
	  my_print_stars.c \
	  my_print_dots.c \
	  my_print_minus.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CC := gcc

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../$(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f ../$(NAME)
