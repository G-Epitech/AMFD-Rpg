/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** impact_player
*/

#include "app/types.h"
#include "app/display/display.h"
#include "app/inventory/types.h"

void inventory_item_impact_player(player_t *player,
inventory_item_t *item, int factor)
{
    if (item) {
        player->intellect += item->target->intelligence * factor;
        player->speed += item->target->speed * factor;
    }
}
