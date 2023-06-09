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
			src/types/ressources/icons/load_skills_tree.c \
			src/types/renderer/destroy.c \
			src/types/renderer/objects/init.c \
			src/types/renderer/objects/destroy.c \
			src/types/renderer/objects/reset.c \
			\
			src/types/list/append.c \
			src/types/list/list.c \
			\
			src/types/sound/load.c	\
			src/types/sound/load_sound_fx.c	\
			src/types/sound/load_sound_themes.c	\
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
			src/types/players/competences.c \
			\
			src/types/items/load_all.c \
			src/types/items/consume.c \
			src/types/items/free.c \
			src/types/items/load.c \
			src/types/items/id.c \
			\
			src/types/characters/rect.c \
			\
			src/types/dialog_box/events.c \
			src/types/dialog_box/free.c \
			src/types/dialog_box/new.c \
			src/types/dialog_box/options.c \
			src/types/dialog_box/input.c \
			src/types/dialog_box/message.c \
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
			src/types/inventory/active.c \
			src/types/inventory/item.c \
			src/types/inventory/remove.c \
			src/types/inventory/id.c \
			\
			src/types/ressources/load.c \
			src/types/ressources/free.c \
			src/types/ressources/maps/load.c \
			src/types/ressources/maps/load_entry.c	\
			src/types/ressources/maps/include_array.c	\
			src/types/ressources/maps/free.c \
			src/types/ressources/maps/prep_collision_layer.c	\
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
			src/types/ressources/components/fight/load.c \
			src/types/ressources/components/progress/load.c \
			src/types/ressources/components/dialog_box/load.c \
			\
			src/types/ressources/inventory/load.c \
			\
			src/types/ressources/icons/load.c \
			\
			src/types/ressources/items/load.c \
			\
			src/types/ressources/animation/load_player.c	\
			src/types/ressources/animation/load_environment.c \
			\
			src/types/saver/new.c \
			src/types/saver/free.c \
			\
			src/types/view/init.c \
			\
			src/app/run.c \
			\
			src/app/init/controller.c \
			src/app/init/init.c \
			src/app/init/interactions.c \
			src/app/init/inventory_event.c \
			src/app/init/dialog_box.c \
			src/app/init/items.c \
			src/app/init/network.c \
			src/app/init/npcs.c \
			src/app/init/players.c \
			src/app/init/settings.c \
			src/app/init/sounds.c \
			src/app/init/tasks.c \
			src/app/init/animations.c \
			src/app/init/quests.c \
			src/app/init/shops.c	\
			\
			src/app/free/animations.c \
			src/app/free/sounds.c	\
			src/app/free/free.c \
			src/app/free/inventory_event.c \
			src/app/free/dialog_box.c \
			src/app/free/characters.c \
			\
			src/app/animations/handler.c \
			src/app/animations/active.c \
			src/app/animations/event_new.c \
			src/app/animations/event_actual.c \
			src/app/animations/screen/zoom.c \
			src/app/animations/screen/fade.c \
			src/app/animations/button/shake_attack.c \
			src/app/animations/text/floating.c \
			src/app/animations/text/notif.c \
      src/app/animations/player/animation.c	\
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
			src/app/settings/set_resolution.c \
			\
			src/app/shop/shop_handler.c	\
			src/app/shop/shop_load_stock.c	\
			src/app/shop/shop_update_stock.c	\
			\
			src/app/window/init.c \
			src/app/window/close.c \
			\
			src/app/events/handler.c \
			src/app/events/window/close.c \
			src/app/events/keyboard/move.c \
			src/app/events/keyboard/inventory.c \
			src/app/events/keyboard/interaction/interaction.c \
			src/app/events/keyboard/interaction/fight/start.c \
			src/app/events/keyboard/interaction/fight/choice.c \
			src/app/events/keyboard/interaction/dialogs/dialogs.c \
			src/app/events/keyboard/interaction/dialogs/continue.c \
			src/app/events/components/buttons.c \
			src/app/events/components/levers.c \
			src/app/events/components/attacks.c \
			src/app/events/components/in_game_menu.c \
			src/app/events/components/dialog_box/dialog_box.c \
			src/app/events/components/dialog_box/options.c \
			src/app/events/components/dialog_box/input.c \
			src/app/events/skills_tree/detect.c \
			src/app/events/skills_tree/find_competence.c \
			\
			src/app/developer/reload_json.c \
			\
			src/app/saving/onexit.c \
			src/app/saving/ingame.c \
			src/app/saving/load_ask_file.c \
			src/app/saving/save/save_ask_file.c \
			src/app/saving/save/player.c \
			src/app/saving/save/quests.c \
			src/app/saving/save/inventory.c \
			src/app/saving/save/competences.c \
			src/app/saving/save/save.c \
			src/app/saving/load/check_player.c \
			src/app/saving/load/check.c \
			src/app/saving/load/load.c \
			src/app/saving/load/inventory.c \
			src/app/saving/load/quests.c \
			src/app/saving/load/competences.c \
			src/app/saving/load/player.c \
			\
			src/app/network/init.c \
			src/app/network/connexion/host.c \
			src/app/network/connexion/join.c \
			src/app/network/send/character.c \
			src/app/network/send/position.c \
			src/app/network/send/string.c \
			src/app/network/send/quests.c \
			src/app/network/receive/receive.c \
			src/app/network/receive/character.c \
			src/app/network/receive/game.c \
			src/app/network/receive/position.c \
			src/app/network/receive/quests.c \
			\
			src/app/core/inventory/move.c \
			src/app/core/inventory/onclick.c \
			src/app/core/inventory/onclick_active.c \
			src/app/core/inventory/onclick_consumable.c \
			src/app/core/inventory/onclick_equipement.c \
			src/app/core/inventory/swap.c \
			src/app/core/inventory/bad_move.c \
			src/app/core/inventory/get_free_position.c \
			src/app/core/inventory/get_item_at_pos.c \
			src/app/core/inventory/impact_player.c \
			src/app/core/inventory/press.c \
			src/app/core/inventory/release.c \
			\
			src/app/display/handler.c \
			src/app/display/map/map.c \
			src/app/display/map/back.c \
			src/app/display/tasks/script_bash/display.c \
			src/app/display/tasks/brute_force/display.c \
			src/app/display/tasks/handler.c \
			src/app/display/npcs/npcs.c \
			src/app/display/player/player.c \
			src/app/display/player/competences_tree.c \
			src/app/display/characters/character.c \
			src/app/display/map/front.c	\
      src/app/display/components/components.c \
			src/app/display/components/backgrounds.c \
			src/app/display/components/levers.c \
			src/app/display/components/interaction.c \
			src/app/display/components/buttons/buttons.c \
			src/app/display/components/buttons/icon.c \
			src/app/display/components/buttons/dispatch.c \
			src/app/display/components/progress/progress.c \
			src/app/display/components/progress/progresses.c \
			src/app/display/menus/menus.c \
			src/app/display/menus/main_menu.c \
			src/app/display/menus/settings.c \
			src/app/display/menus/select_character.c \
			src/app/display/inventory/grids.c \
			src/app/display/inventory/grids_taken.c \
			src/app/display/inventory/grids_empty.c \
			src/app/display/inventory/grids_specials.c \
			src/app/display/inventory/item_box.c \
			src/app/display/inventory/profile.c \
			src/app/display/inventory/inventory.c \
			src/app/display/inventory/items_content.c \
			src/app/display/inventory/items_masks.c \
			src/app/display/inventory/levels.c \
			src/app/display/developer/collisions.c \
			src/app/display/developer/position.c \
			src/app/display/dialog_box/dialog_box.c \
			src/app/display/dialog_box/options.c \
			src/app/display/dialog_box/input.c \
			src/app/display/fight/fight.c \
			src/app/display/fight/choice.c \
			src/app/display/fight/attack.c \
			src/app/display/animations/animations.c \
			src/app/display/animations/floating_text.c \
			src/app/display/animations/notif.c \
			src/app/display/animations/fade.c \
			src/app/display/dialogs/dialogs.c \
			src/app/display/hud/hud.c \
			src/app/display/animations/environment.c \
			src/app/display/shop/shop.c	\
			src/app/display/shop/display_stock.c	\
			src/app/display/shop/display_shop_info.c	\
			\
			src/app/getters/progress/inventory.c \
			src/app/getters/progress/fight.c \
      		\
			src/app/display/tasks/camera/display.c \
			src/app/display/tasks/camera/solution.c \
			src/app/display/tasks/camera/result.c \
			src/app/display/tasks/camera/equations.c \
			src/app/display/tasks/flipper/display.c \
			\
			src/app/utils/test.c \
			src/app/utils/player/give_xp.c \
			\
			src/app/loading/loading_company_screen.c \
			src/app/loading/loading_screen_text.c \
			src/app/loading/loading_sleep.c \
			\
			src/app/events/handler/closed.c \
			src/app/events/handler/mouse_button_pressed.c \
			src/app/events/handler/pressed.c \
			src/app/events/handler/released.c \
			src/app/events/handler/text_entered.c \
			src/app/events/handler/mouse_button_released.c \
			src/app/events/handler/mouse_move.c \
			src/app/events/shop/event_shop_buy.c \
			\
			src/app/core/handler.c	\
			src/app/core/animation.c	\
			\
			src/app/core/tasks/flipper/create_node.c \
			src/app/core/tasks/flipper/game_handler.c \
			src/app/core/tasks/flipper/init_node.c \
			src/app/core/tasks/flipper/reset_setup.c \
			src/app/core/tasks/flipper/create_circle.c \
			src/app/core/tasks/flipper/circle_handler.c \
			src/app/core/tasks/flipper/click_circle.c \
			src/app/core/tasks/camera/create_node.c \
			src/app/core/tasks/camera/game_handler.c \
			src/app/core/tasks/camera/reset_setup.c \
			src/app/core/tasks/camera/init_node.c \
			src/app/core/tasks/camera/valid_solution.c \
			src/app/core/tasks/camera/write_solution.c \
			src/app/core/tasks/brute_force/create_node.c \
			src/app/core/tasks/brute_force/game_handler.c \
			src/app/core/tasks/brute_force/reset_setup.c \
			src/app/core/tasks/brute_force/init_node.c \
			src/app/core/tasks/brute_force/click.c \
			src/app/core/tasks/brute_force/released.c \
			src/app/core/interactions/movement.c \
			src/app/core/interactions/npc.c \
			src/app/core/interactions/travel.c	\
			src/app/core/interactions/interactions.c	\
			src/app/core/interactions/shop.c	\
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
			src/app/core/fight/handler.c \
			src/app/core/fight/enemy.c \
			src/app/core/sound.c \
			src/app/core/quests/quests.c \
			src/app/core/quests/npc.c \
			src/app/core/quests/get.c \
			src/app/core/quests/upgrade.c \
			src/app/core/quests/world.c \
			src/app/core/quests/tree.c \
			src/app/core/quests/bash.c \
			\
			src/app/sound/sound_control.c \
			src/app/sound/handle_sound_fx.c	\
			src/app/sound/handle_sound_themes.c	\
			src/app/sound/handle_sound_volume.c	\
			\
			src/app/in_game_menu/in_game_menu.c	\
			src/app/in_game_menu/restart_session/restart_session.c	\
			src/app/in_game_menu/restart_session/restart_player.c	\
			src/app/in_game_menu/restart_session/restart_sound.c	\
			\
			src/types/shop/load.c	\
			src/types/shop/include_array.c	\
			src/app/tasks/bash_use.c \

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
