##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC = my_compute_factorial_it.c	\
      my_compute_factorial_rec.c \
      my_compute_power_it.c \
      my_compute_power_rec.c \
      my_compute_square_root.c \
      my_debug.c \
      my_evil_str.c \
      my_find_prime_sup.c \
      my_getnbr.c \
      my_isalpha.c \
      my_isneg.c \
      my_isnum.c \
      my_is_prime.c \
      my_power.c \
      my_putchar.c \
      my_put_nbr.c \
      my_putstr.c \
      my_revstr.c \
      my_showmem.c \
      my_showstr.c \
      my_show_word_array.c \
      my_sort_int_array.c \
      my_strcapitalize.c \
      my_strcat.c \
      my_strcmp.c \
      my_strcpy.c \
      my_strdup.c \
      my_str_islower.c \
      my_str_isprintable.c \
      my_str_isupper.c \
      my_strlen.c \
      my_strlowcase.c \
      my_strncat.c \
      my_strncmp.c \
      my_strncpy.c \
      my_strstr.c \
      my_str_to_word_array.c \
      my_strupcase.c \
      my_swap.c \
      error.c \
      nbr_to_str.c

OBJ = $(SRC:.c=.o)

NAME = my

COLOUR_GREEN=\033[0;32m

COLOUR_ORANGE=\033[0;33m

COLOUR_RED=\033[0;31m

COLOUR_BLUE=\033[0;34m

BOLD_BLUE=\033[1;34m

COLOUR_GREY=\033[0;30m

COLOUR_END=\033[0m

all: 		$(NAME)

$(NAME):	$(OBJ)
			@ar rc lib$(NAME).a *.o
			@cp lib$(NAME).a ../
			@mkdir -p ../../include

%.o: %.c
			@echo "$(COLOUR_BLUE)📦 Compiling lib$(NAME) - $(BOLD_BLUE)\
                  [$<]$(COLOUR_END)"
			@gcc -c $< -o $@

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f lib$(NAME).a
			rm -f ../lib$(NAME).a

re: 		fclean all
