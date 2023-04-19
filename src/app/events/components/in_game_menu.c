/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** In game menu events
*/

#include <SFML/Graphics.h>
#include "app/events/events.h"
#include "app/app.h"
#include "my/include/my.h"

void event_pause_menu(sfEvent event, app_t *app)
{
    if (event.key.code == sfKeyEscape && app->state == ST_INGAME) {
        app->state = ST_BREAK;
        return;
    }
    if (event.key.code == sfKeyEscape && app->state == ST_BREAK)
        app->state = ST_INGAME;
}
