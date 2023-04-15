/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load components ressources
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/components/components.h"
#include "app/loading/loading.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"

static void insert_data(list_t *list, cjson_t *config)
{
    node_data_t data;
    node_t *node = NULL;
    attack_t *attack = malloc(sizeof(attack_t));
    char *texture = NULL;

    if (!attack)
        return;
    cjson_get_prop_string(config, "texture", &texture);
    attack->texture = sfTexture_createFromFile(texture, NULL);
    cjson_get_prop_string(config, "title", &attack->title);
    cjson_get_prop_int(config, "level", &attack->level);
    cjson_get_prop_int(config, "mana", &attack->mana);
    cjson_get_prop_int(config, "damage", &attack->damage);
    attack->position = cjson_vector(config, "position");
    data.attack = attack;
    node = node_new(data);
    list_append(list, node);
    free(texture);
}

list_t *ressources_components_fight_load(cjson_t *config)
{
    list_t *list = list_new();
    cjson_array_t *array = cjson_get_array_unsafe(config);
    cjson_t *node = array->first;

    while (node) {
        insert_data(list, node);
        node = node->next;
    }
    return list;
}
