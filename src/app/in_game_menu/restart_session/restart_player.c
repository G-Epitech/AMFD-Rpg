/*
** EPITECH PROJECT, 2023
** EPG
** File description:
** Restarts player
*/

#include "app/types.h"
#include "types/list/list.h"
#include "types/characters/types.h"
#include "types/players/players.h"

static void reset_player_inventory(player_t *player)
{
    node_t *node = player->inventory->first;
    node_t *next = NULL;
    inventory_item_t *item = NULL;

    while (node) {
        next = node->next;
        item = node->data.inventory_item;
        inventory_remove_item(player, item);
        node = next;
    }
}

void restart_player(player_t *player)
{
    if (!player)
        return;
    player->position = PLAYER_DEFAULT_SPAWN;
    player->state = IDLE;
    player->skin_id = -1;
    player->orientation = SO_LEFT;
    player->rect = (sfIntRect) {0, 0, 0, 0};
    init_levels(player);
    reset_player_inventory(player);
}
