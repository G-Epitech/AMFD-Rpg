/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** Loads map entries
*/

#include <stdlib.h>
#include "types/list/list.h"
#include "types/components/components.h"
#include "cjson/include/cjson.h"

static void load_entry_properties(cjson_t *config, list_t *entry_list)
{
    node_t *node = NULL;
    entry_t *entry = malloc(sizeof(entry_t));

    if (!entry)
        return;
    entry->child = cjson_get_prop_int_unsafe(config, "child");
    entry->direction = cjson_get_prop_int_unsafe(config, "direction");
    entry->tile_size = cjson_get_prop_int_unsafe(config, "tile_size");
    entry->player_spawn = cjson_vector(config, "player_spawn");
    entry->pos = cjson_vector(config, "pos");
    node = node_new((node_data_t) entry);
    if (node)
        list_append(entry_list, node);
}

list_t *map_load_entry(cjson_t *map_config)
{
    list_t *entry = list_new();
    cjson_array_t *entry_list = NULL;
    cjson_t *entry_obj = NULL;

    if (!cjson_get_prop_array(map_config, "entry", &entry_list))
        return NULL;
    entry_obj = entry_list->first;
    while (entry_obj) {
        load_entry_properties(entry_obj, entry);
        entry_obj = entry_obj->next;
    }
    return entry;
}
