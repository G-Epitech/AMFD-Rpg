/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Add new player to list
*/

#include <stdlib.h>
#include "my/include/my.h"
#include "types/list/list.h"
#include "types/list/types.h"
#include "types/players/types.h"
#include "types/characters/types.h"

player_t *players_add(list_t *list, char *name)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->inventory = list_new();
    if (!player->inventory)
        return NULL;
    player->position = PLAYER_DEFAULT_SPAWN;
    player->skin_id = -1;
    player->orientation = SO_LEFT;
    player->colision_pos = (sfVector2f) {PLAYER_DEFAULT_SPAWN.x / 16,
    PLAYER_DEFAULT_SPAWN.y / 16};
    player->name = my_strdup(name);
    player->xp = 1;
    list_append(list, node_new((node_data_t) player));
    return player;
}
