/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Add new player to list
*/

#include <stdlib.h>
#include "types/list/list.h"
#include "types/list/types.h"
#include "types/players/types.h"
#include "types/character/types.h"

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
    data.player->skin_id = 0;
    data.player->orientation = SO_LEFT;
    data.player->name = name;
    data.player->xp = 1;
    list_append(list, node_new(data));
    return data.player;
}
