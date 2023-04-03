/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Add new player to list
*/

#include <stdlib.h>
#include "types/players/types.h"
#include "types/list/types.h"
#include "types/list/list.h"

player_t *players_add(list_t *list, char *name)
{
    node_data_t data;
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    data.player = player;
    data.player->inventory = list_new();
    if (!data.player->inventory)
        return NULL;
    data.player->position = PLAYER_DEFAULT_SPAWN;
    data.player->colision_pos = (sfVector2f) {4, 3};
    data.player->skin = NULL;
    data.player->name = name;
    data.player->xp = 1;
    list_append(list, node_new(data));
    return data.player;
}
