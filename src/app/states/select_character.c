/*
** EPITECH PROJECT, 2023
** select_character.c
** File description:
** Select your character in the menu
*/

#include "types/characters/types.h"
#include "types/renderer/types.h"
#include "app/network/network.h"
#include "app/types.h"
#include "app/animations/animations.h"

static void set_select_skin_duo(app_t *app, button_t *button)
{
    if (button->position.x == LUCAS_POSITION && app->partner->skin_id !=
    STX_LUCAS) {
        app->player->skin_id = STX_LUCAS;
        network_send_character(app, STX_LUCAS);
    }
    if (button->position.x == TOM_POSITION && app->partner->skin_id !=
    STX_TOM) {
        app->player->skin_id = STX_TOM;
        network_send_character(app, STX_TOM);
    }
}

static void set_select_skin_solo(app_t *app, button_t *button)
{
    if (button->position.x == LUCAS_POSITION) {
        app->player->skin_id = STX_LUCAS;
    }
    if (button->position.x == TOM_POSITION) {
        app->player->skin_id = STX_TOM;
    }
}

int states_select_character(renderer_t *renderer, app_t *app, button_t *button)
{
    list_t *events = animation_event_new(app);
    (void) renderer;
    if (!app->partner) {
        set_select_skin_solo(app, button);
        app->state = ST_INGAME;
        animations_screen_fade_add(events, true);
        return 0;
    }
    if (app->player->skin_id != -1)
        return 1;
    set_select_skin_duo(app, button);
    return 0;
}
