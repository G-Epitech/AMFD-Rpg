/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** enemy
*/

#include <stdlib.h>
#include "types/npc/types.h"

void npc_destroy_world_enemy(npc_enemy_t *enemy)
{
    if (enemy) {
        free(enemy->attacks);
    }
    free(enemy);
}
