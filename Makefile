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
			src/types/npc/load/include_array.c \
			src/types/npc/destroy/worlds_data.c \
			src/types/npc/destroy/destroy_all.c \
			src/types/npc/destroy/enemy.c \
			src/types/npc/get.c \
			\
			src/types/players/init.c \
			src/types/players/add.c \
			src/types/players/inventory.c \
			\
			src/types/items/load_all.c \
			src/types/items/load.c \
			\
			src/types/characters/rect.c \
			\
			src/types/components/load.c \
			src/types/components/vector.c \
			src/types/components/buttons/append.c \
			src/types/components/buttons/load.c \
			src/types/components/levers/append.c \
			src/types/components/levers/load.c \
			src/types/components/progress/load.c \
			\
			src/types/inventory/add.c \
			src/types/inventory/item.c \
			src/types/inventory/remove.c \
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
			src/types/ressources/components/progress/load.c \
			\
			src/types/ressources/inventory/load.c \
			\
			src/types/ressources/icons/load.c \
			\
			src/types/ressources/items/load.c \
			\
			src/types/view/init.c \
			\
			src/app/run.c \
			\
			src/app/init/controller.c \
			src/app/init/init.c \
			src/app/init/interactions.c \
			src/app/init/items.c \
			src/app/init/network.c \
			src/app/init/npcs.c \
			src/app/init/players.c \
			src/app/init/settings.c \
			src/app/init/tasks.c \
			\
			src/app/free/free.c \
			\
			src/app/states/on_state.c \
			src/app/states/switch.c \
			src/app/states/select_character.c \
			\
			src/app/settings/music.c \
			src/app/settings/fullscreen.c \
			src/app/settings/developer.c \
			src/app/settings/volume.c \
			src/app/settings/fps.c \
			\
			src/app/window/init.c \
			src/app/window/close.c \
			\
			src/app/events/handler.c \
			src/app/events/window/close.c \
			src/app/events/keyboard/move.c \
			src/app/events/components/buttons.c \
			src/app/events/components/levers.c \
			\
			src/app/developer/reload_json.c \
			\
			src/app/network/init.c \
			src/app/network/connexion/host.c \
			src/app/network/connexion/join.c \
			src/app/network/send/character.c \
			src/app/network/send/position.c \
			src/app/network/send/string.c \
			src/app/network/receive/receive.c \
			src/app/network/receive/character.c \
			src/app/network/receive/game.c \
			src/app/network/receive/position.c \
			\
			src/app/core/tasks/handler.c \
			src/app/core/tasks/create.c \
			src/app/core/tasks/find_node.c \
			src/app/core/tasks/script_bash/create_node.c \
			src/app/core/tasks/script_bash/init_node.c \
			src/app/core/tasks/script_bash/game_handler.c \
			src/app/core/tasks/script_bash/write_cmd.c \
			src/app/core/tasks/script_bash/valid_cmd.c \
			src/app/core/tasks/script_bash/reset_setup.c \
			src/app/core/tasks/script_bash/create_list.c \
			\
			src/app/display/handler.c \
			src/app/display/map/map.c \
			src/app/display/map/back.c \
			src/app/display/tasks/script_bash/display.c \
			src/app/display/tasks/brute_force/display.c \
			src/app/display/tasks/handler.c \
			src/app/display/npcs/npcs.c \
			src/app/display/player/player.c \
			src/app/display/characters/character.c \
			src/app/display/map/front.c	\
      		src/app/display/components/components.c \
			src/app/display/components/backgrounds.c \
			src/app/display/components/levers.c \
			src/app/display/components/buttons/buttons.c \
			src/app/display/components/buttons/icon.c \
			src/app/display/components/buttons/dispatch.c \
			src/app/display/menus/menus.c \
			src/app/display/menus/main_menu.c \
			src/app/display/menus/settings.c \
			src/app/display/menus/select_character.c \
			src/app/display/inventory/grids.c \
			src/app/display/inventory/item_box.c \
			src/app/display/inventory/profile.c \
			src/app/display/inventory/inventory.c \
			src/app/display/inventory/items_content.c \
			src/app/display/developer/collisions.c \
			src/app/display/developer/position.c \
			\
			src/app/utils/test.c \
			\
			src/app/loading/loading_company_screen.c \
			src/app/loading/loading_screen_text.c \
			src/app/loading/loading_sleep.c \
			\
			src/app/core/tasks/brute_force/create_node.c \
			src/app/core/tasks/brute_force/game_handler.c \
			src/app/core/tasks/brute_force/reset_setup.c \
			src/app/core/tasks/brute_force/init_node.c \
			src/app/core/tasks/brute_force/click.c \
			src/app/core/tasks/brute_force/released.c \
			src/app/core/handler.c	\
			src/app/core/interactions/movement.c \
			src/app/core/interactions/npc.c \
			\
			src/app/events/handler/closed.c \
			src/app/events/handler/mouse_button_pressed.c \
			src/app/events/handler/pressed.c \
			src/app/events/handler/released.c \
			src/app/events/handler/text_entered.c \
			src/app/events/handler/mouse_button_released.c \
			\
			src/app/core/tasks/flipper/create_node.c \
			src/app/core/tasks/flipper/game_handler.c \
			src/app/core/tasks/flipper/init_node.c \
			src/app/core/tasks/flipper/reset_setup.c \
			src/app/core/tasks/flipper/create_circle.c \
			src/app/core/tasks/flipper/circle_handler.c \
			src/app/core/tasks/flipper/click_circle.c \
			src/app/display/tasks/flipper/display.c \


NAME = my_rpg

FTEST_REPO = https://github.com/Atomot/ftest/

FTEST_V = ftest-0.1.0-1.x86_64.rpm

CFLAGS += -Wall -Wextra -Werror -Wno-unused-command-line-argument -g

INC = -I./include -I./lib

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window \
-lcsfml-network -L./lib -lmy -lcjson -lm

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
