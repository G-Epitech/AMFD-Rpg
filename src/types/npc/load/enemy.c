/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** enemy
*/

#include <stdlib.h>
#include <stdbool.h>
#include "types/npc/npc.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"

static void set_enemy_in_world(npc_enemy_t *enemy, npc_data_t *world_data)
{
    world_data->enemy = malloc(sizeof(npc_enemy_t));
    if (!world_data->enemy)
        return;
    (*world_data->enemy) = *enemy;
}

void npc_load_world_enemy(cjson_t *config, npc_data_t *world_data)
{
    npc_enemy_t enemy = {0, 0, NULL, 0};
    cjson_array_t *attacks = NULL;

    if (!cjson_get_prop_array(config, "attacks", &attacks))
        return;
    if (!cjson_get_prop_int(config, "level", &enemy.level))
        return;
    if (!cjson_get_prop_int(config, "life", &enemy.life))
        return;
    enemy.attacks = cjson_array_to_int_array(attacks, &enemy.nb_attacks);
    set_enemy_in_world(&enemy, world_data);
}
