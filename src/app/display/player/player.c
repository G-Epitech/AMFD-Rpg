/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player
*/

#include <stdio.h>
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

static void display_specific_player(renderer_t *renderer, player_t *player)
{
    sfVector2f position = player->position;
    int skin_id = player->skin_id;
    skin_orientation_t orientation = player->orientation;

    display_character(renderer, position, skin_id, orientation);
}

void display_player(renderer_t *renderer, app_t *app)
{
    list_t *players = app->players;
    node_t *node = players->first;
    player_t *player = NULL;

    while (node) {
        player = node->data.player;
        display_specific_player(renderer, player);
        node = node->next;
    }
}
