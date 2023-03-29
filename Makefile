##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC_FILES = \


NAME = my_rpg

FTEST_REPO = https://github.com/Atomot/ftest/
FTEST_V = ftest-0.1.0-1.x86_64.rpm

CFLAGS = -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window \
-L./lib -lmy -lm
IFLAGS = -I./include
PATH_MY = lib/my

$(NAME):
			@make -C$(PATH_MY) -s
			@gcc -o $(NAME) $(SRC_FILES) $(CFLAGS) $(IFLAGS) -g
all: 		$(NAME)

clean:
			@make -C$(PATH_MY) clean -s

fclean: 	clean
			@rm -f $(NAME)
			@make -C$(PATH_MY) fclean -s

re: 		fclean all

tests_run:
		echo "pass"

criterion:
		echo "pass"

ftest:
		echo "pass"

custom:
		echo "pass"
