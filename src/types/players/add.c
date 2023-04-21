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

static void init_levels(player_t *player)
{
    player->xp = 0;
    player->level = 0;
    player->life = 20;
    player->intellect = 3;
    player->speed = 3;
    player->intellect_max = 10;
    player->speed_max = 10;
    player->life_max = 20;
    player->xp_max = 10;
}

player_t *players_add(list_t *list, char *name)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->inventory = list_new();
    if (!player->inventory)
        return NULL;
    player->position = PLAYER_DEFAULT_SPAWN;
    player->state = IDLE;
    player->skin_id = -1;
    player->orientation = SO_LEFT;
    player->name = my_strdup(name);
    player->rect = (sfIntRect) {0, 0, 0, 0};
    init_levels(player);
    list_append(list, node_new((node_data_t) player));
    return player;
}
