##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC = main.c \
			\
			src/types/renderer/init.c \
			src/types/renderer/destroy.c \
			src/types/list/append.c \
			src/types/list/list.c \
			src/types/node/node.c \
			src/types/node/swap.c \
			src/types/players/init.c \
			src/types/players/add.c \
			src/types/components/load.c \
			src/types/components/buttons/append.c \
			src/types/components/buttons/load.c \
			src/types/components/levers/append.c \
			src/types/components/levers/load.c \
			\
			src/app/window/init.c

NAME = my_rpg

FTEST_REPO = https://github.com/Atomot/ftest/

FTEST_V = ftest-0.1.0-1.x86_64.rpm

CFLAGS += -Wall -Wextra -Wno-unused-command-line-argument

INC = -I./include -I./lib

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window \
-L./lib -lmy -lcjson

OBJ = $(SRC:.c=.o)

PATH_MY = lib/my

PATH_CJSON = lib/cjson

COLOUR_GREEN=\033[0;32m

COLOUR_ORANGE=\033[0;33m

COLOUR_RED=\033[0;31m

COLOUR_BLUE=\033[0;34m

COLOUR_GREY=\033[0;30m

COLOUR_END=\033[0m

.PHONY: all clean fclean re

$(NAME):	$(OBJ)
			@echo "$(COLOUR_RED)🚚 Lib 'My' compliation...$(COLOUR_END)"
			@make -C$(PATH_MY)
			@echo "$(COLOUR_RED)🚚 Lib 'CJSON' compliation...$(COLOUR_END)"
			@make -C$(PATH_CJSON)
			@echo "$(COLOUR_RED)🚚 Main compliation...$(COLOUR_END)"
			@gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(INC)
			@echo "$(COLOUR_GREEN)✅ Hackers-Quest was successfully built\
			$(COLOUR_END)"

%.o: 		%.c
			@echo "$(COLOUR_BLUE)📑 Compiling $(BOLD_BLUE)[$<]$(COLOUR_END)"
			@gcc $(LDFLAGS) $(CFLAGS) $(INC) -c $< -o $@

all: 		$(NAME)

clean:
			@make -C$(PATH_MY) clean -s
			@make -C$(PATH_CJSON) clean -s

fclean: 	clean
			@rm -f $(NAME)
			@rm -f $(OBJ)
			@make -C$(PATH_MY) fclean -s
			@make -C$(PATH_CJSON) fclean -s
			@echo "$(COLOUR_ORANGE)🧽 Hackers-Quest was successfully clean\
			$(COLOUR_END)"

re: 		fclean all

tests_run:
		echo "pass"

criterion:
		echo "pass"

ftest:
		echo "pass"

custom:
		echo "pass"
