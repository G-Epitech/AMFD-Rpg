##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## @Made by Math alias T1nt1n
##

SRC = 		src/main.c \
			\
			src/types/renderer/init.c \
			src/types/renderer/load.c	\
			src/types/renderer/destroy.c \
			src/types/renderer/objects/init.c \
			src/types/renderer/objects/destroy.c \
			src/types/renderer/objects/reset.c \
			\
			src/types/list/append.c \
			src/types/list/list.c \
			\
			src/types/node/node.c \
			src/types/node/swap.c \
			\
			src/types/npc/load/dialogs.c \
			src/types/npc/load/load_all.c \
			src/types/npc/load/load.c \
			src/types/npc/load/enemy.c \
			src/types/npc/load/world_data.c \
			src/types/npc/load/worlds_data.c \
			src/types/npc/destroy/worlds_data.c \
			src/types/npc/destroy/destroy_all.c \
			src/types/npc/destroy/enemy.c \
			src/types/npc/get.c \
			\
			src/types/players/init.c \
			src/types/players/add.c \
			\
			src/types/components/load.c \
			src/types/components/vector.c \
			src/types/components/buttons/append.c \
			src/types/components/buttons/load.c \
			src/types/components/levers/append.c \
			src/types/components/levers/load.c \
			\
			src/types/ressources/load.c \
			src/types/ressources/free.c \
			src/types/ressources/maps/load.c \
			src/types/ressources/maps/free.c \
			\
			src/types/ressources/skins/load.c \
			src/types/ressources/skins/free.c \
			src/types/ressources/skins/get.c \
			\
			src/types/ressources/components/init.c \
			src/types/ressources/components/load.c \
			src/types/ressources/components/button/load.c \
			src/types/ressources/components/backgrounds/load.c \
			src/types/ressources/components/lever/load.c \
			\
			src/types/view/init.c \
			\
			src/app/init.c \
			src/app/run.c \
			\
			src/app/states/on_state.c \
			src/app/states/settings.c \
			src/app/states/main_menu.c \
			src/app/states/help.c \
			src/app/states/switch.c \
			\
			src/app/window/init.c \
			src/app/window/close.c \
			\
			src/app/events/handler.c \
			src/app/events/window/close.c \
			src/app/events/keyboard/move.c \
			src/app/events/components/buttons.c \
			\
			src/app/display/handle.c \
			src/app/display/map/map.c \
			src/app/display/map/back.c \
			\
			src/app/core/tasks/handler.c \
			src/app/core/tasks/create.c \
			src/app/core/tasks/script_bash/create_node.c \
			src/app/core/tasks/script_bash/init_node.c \
			src/app/core/tasks/script_bash/game_handler.c \
			src/app/core/tasks/script_bash/write_cmd.c \
			src/app/core/tasks/script_bash/valid_cmd.c \
			src/app/core/tasks/script_bash/reset_setup.c \
			src/app/core/tasks/script_bash/create_list.c \
			src/app/display/tasks/script_bash/display.c \
			src/app/display/tasks/handler.c \
			\
			src/app/display/npcs/npcs.c \
			src/app/display/player/player.c \
			src/app/display/characters/character.c \
			src/app/display/map/front.c	\
			src/app/display/components/buttons.c \
      		src/app/display/components/components.c \
			src/app/display/components/backgrounds.c \
			src/app/display/components/icon.c \
			src/app/display/menus/menus.c \
			src/app/display/menus/main_menu.c \
			src/app/display/menus/settings.c \
			\
			src/app/core/handler.c	\
			src/app/core/movement.c	\
			\
			src/app/utils/test.c \
			\
			src/app/loading/loading_company_screen.c \
			src/app/loading/loading_screen_text.c

NAME = my_rpg

FTEST_REPO = https://github.com/Atomot/ftest/

FTEST_V = ftest-0.1.0-1.x86_64.rpm

CFLAGS += -Wall -Wextra -Werror -Wno-unused-command-line-argument -g

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


$(NAME):	$(OBJ)
			@printf "$(COLOUR_RED)🚚 Lib 'My' compliation...$(COLOUR_END)\n"
			@make -C$(PATH_MY)
			@printf "$(COLOUR_RED)🚚 Lib 'CJSON' compliation...$(COLOUR_END)\n"
			@make -C$(PATH_CJSON)
			@printf "$(COLOUR_RED)🚚 Main compliation...$(COLOUR_END)\n"
			@gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(INC)
			@printf "$(COLOUR_GREEN)✅ Hackers-Quest was successfully built\
			$(COLOUR_END)\n"

%.o: 		%.c
			@printf "$(COLOUR_BLUE)📑 Compiling $(BOLD_BLUE)[$<]$(COLOUR_END)\n"
			@gcc $(LDFLAGS) $(CFLAGS) $(INC) -c $< -o $@

all: 		$(NAME)

clean:
			@rm -f $(NAME)
			@rm -f $(OBJ)
			@make -C$(PATH_MY) clean -s
			@make -C$(PATH_CJSON) clean -s

fclean: 	clean
			@make -C$(PATH_MY) fclean -s
			@make -C$(PATH_CJSON) fclean -s
			@printf "$(COLOUR_ORANGE)🧽 Hackers-Quest was successfully clean\
			$(COLOUR_END)\n"

re: 		fclean all

style:		fclean
			@echo "$(COLOUR_RED)🔍 Checking coding style...$(COLOUR_END)"
			@coding-style . .
			@cat coding-style-reports.log

exec:		$(NAME)
			./$(NAME)

tests_run:
			echo "pass"

criterion:
			echo "pass"

ftest:
			echo "pass"

custom:
			echo "pass"

.PHONY = all clean fclean re
