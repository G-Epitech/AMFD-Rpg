/*
** EPITECH PROJECT, 2023
** inventory.c
** File description:
** Inventory keyboard
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "app/app.h"
#include "types/players/types.h"
#include "app/events/events.h"
#include "types/npc/npc.h"
#include "types/list/list.h"
#include "app/animations/animations.h"

void keyboard_inventory(sfEvent event, app_t *app)
{
    if (event.key.code == sfKeyE && app->state == ST_INGAME) {
        app->state = ST_INVENTORY;
    }
}
