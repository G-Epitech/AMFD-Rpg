/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** In game menu events
*/

#include <SFML/Graphics.h>
#include "app/events/events.h"
#include "app/app.h"
#include "app/in_game_menu/in_game_menu.h"

void event_pause_menu(sfEvent event, app_t *app)
{
    if (event.key.code == sfKeyEscape && (app->state == ST_INGAME ||
    app->state > ST_TASK)) {
        update_prev_app_state(app);
        app->state = ST_BREAK;
        return;
    }
    if (event.key.code == sfKeyEscape && app->state == ST_BREAK)
        app->state = app->prev_state;
}
