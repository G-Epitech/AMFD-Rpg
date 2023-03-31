/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Add new player to list
*/

#include <stdlib.h>
#include "types/palyers/types.h"
#include "types/list/types.h"
#include "types/list/list.h"

player_t *players_add(list_t *list, char *name)
{
    node_data_t data;

    data.player->inventory = list_new();
    if (!data.player->inventory)
        return NULL;
    data.player->position = (sfVector2f) {0, 0};
    data.player->skin = NULL;
    data.player->name = name;
    list_append(list, node_new(data));
    return data.player;
}
