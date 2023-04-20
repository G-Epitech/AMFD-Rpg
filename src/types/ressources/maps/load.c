/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load maps
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/components/components.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"
#include "app/loading/loading.h"
#include "my/include/my.h"

static void maps_append_data(map_t *map, cjson_t *map_config)
{
    char *back = cjson_get_prop_string_unsafe(map_config, "back");
    char *front = cjson_get_prop_string_unsafe(map_config, "front");
    char *collision = cjson_get_prop_string_unsafe(map_config, "collision");

    map->world = cjson_get_prop_int_unsafe(map_config, "world");
    map->back = sfTexture_createFromFile(back, NULL);
    map->front = sfTexture_createFromFile(front, NULL);
    map->collision = sfImage_createFromFile(collision);
    map->building = cjson_get_prop_bool_unsafe(map_config, "building");
    map->city = cjson_get_prop_int_unsafe(map_config, "city");
    map->enter = cjson_vector(map_config, "enter");
    map->exit = cjson_vector(map_config, "exit");
    map->door = cjson_vector(map_config, "door");
    free(back);
    free(front);
    free(collision);
}

static void maps_append(list_t *maps, cjson_t *map_config, int i,
renderer_t *renderer)
{
    node_data_t data;
    node_t *node = NULL;
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return;
    data.map = map;
    node = node_new(data);
    if (!node) {
        free(map);
        return;
    }
    load_screen_add_bar(renderer, 3, "Chargement des ressources...",
    my_strcat("Map sol ", nbr_to_str(i)));
    maps_append_data(map, map_config);
    list_append(maps, node);
}

void maps_load(list_t *maps, renderer_t *renderer)
{
    cjson_t *maps_config = cjson_parse_file(RESSOURCES_MAPS_CONFIG);
    cjson_array_t *array = NULL;
    cjson_t *map = NULL;
    int i = 0;

    load_screen_add_bar(renderer, 2, "Chargement des ressources...",
    "Chargement des maps");
    if (!maps_config)
        return;
    if (!cjson_get_prop_array(maps_config, "maps", &array))
        return cjson_free(maps_config);
    map = array->first;
    while (map) {
        i++;
        maps_append(maps, map, i, renderer);
        map = map->next;
    }
    cjson_free(maps_config);
}
