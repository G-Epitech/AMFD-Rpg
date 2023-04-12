/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** close
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "types/list/types.h"
#include "types/renderer/types.h"

int inventory_close(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    app->state = ST_INGAME;
    return 0;
}
