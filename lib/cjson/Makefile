##
## EPITECH PROJECT, 2023
## Makefile template
## File description:
## Makefile
##


SRC =		display/array.c \
			display/bool.c \
			display/display.c \
			display/null.c \
			display/number.c \
			display/object.c \
			display/string.c \
			\
			getters/array.c \
			getters/bool.c \
			getters/number.c \
			getters/string.c \
			\
			parse/values/array.c \
			parse/values/bool.c \
			parse/values/null.c \
			parse/values/number.c \
			parse/values/object.c \
			parse/values/string.c \
			parse/file.c \
			parse/key.c \
			parse/parse.c \
			parse/separator.c \
			parse/value.c \
			\
			stringify/size/array.c \
			stringify/size/bool.c \
			stringify/size/null.c \
			stringify/size/number.c \
			stringify/size/object.c \
			stringify/size/size.c \
			stringify/size/string.c \
			stringify/array.c \
			stringify/bool.c \
			stringify/null.c \
			stringify/number.c \
			stringify/object.c \
			stringify/string.c \
			stringify/stringify.c \
			\
			types/array/append.c \
			types/array/array.c \
			types/array/get.c \
			types/array/remove.c \
			types/array/from_bool.c \
			types/array/from_float.c \
			types/array/from_int.c \
			types/array/from_string.c \
			types/array/to_bool.c \
			types/array/to_float.c \
			types/array/to_int.c \
			types/array/to_string.c \
			\
			types/cjson/props/array.c \
			types/cjson/props/bool.c \
			types/cjson/props/number.c \
			types/cjson/props/string.c \
			types/cjson/free.c \
			types/cjson/new.c \
			types/cjson/prop.c \
			types/cjson/set.c \
			\
			utils/charstr.c \
			utils/error.c \
			utils/file.c \
			utils/skip.c \
			utils/strcmp.c \
			utils/strdup.c \
			utils/strlen.c \
			utils/strncpy.c \

OBJ = 			$(SRC:.c=.o)

INC =			-I ./include

NAME = cjson

COLOUR_GREEN=\033[0;32m

COLOUR_ORANGE=\033[0;33m

COLOUR_RED=\033[0;31m

COLOUR_BLUE=\033[0;34m

BOLD_BLUE=\033[1;34m

COLOUR_GREY=\033[0;30m

COLOUR_END=\033[0m

all: 		$(NAME)

$(NAME):	$(OBJ)
			@ar rc lib$(NAME).a $(OBJ)
			@mv lib$(NAME).a ../lib$(NAME).a

%.o: %.c
			@echo "$(COLOUR_BLUE)📦 Compiling lib$(NAME) - $(BOLD_BLUE)\
[$<]$(COLOUR_END)"
			@gcc -c $< -o $@ $(INC)

clean:
			@rm -f $(OBJ)

fclean: 	clean
			@rm -f lib$(NAME).a
			@rm -f ../lib$(NAME).a

re: 		fclean all
