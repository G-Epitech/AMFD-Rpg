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
#include "types/players/types.h"
#include "cjson/include/cjson.h"

static void maps_load_line_collision(map_t *map, cjson_array_t *array)
{
    cjson_t *line = NULL;
    cjson_array_t *lines = NULL;
    size_t len = 0;

    for (size_t i = 0; i < array->len; i++) {
        line = array->first;
        map->collision_layer[i] = malloc(sizeof(int) *
        line->value.v_array->len);
        if (map->collision_layer[i] == NULL)
            return;
        cjson_get_array(line, &lines);
        map->collision_layer[i] = cjson_array_to_int_array(lines, &len);
        array->first = array->first->next;
    }
}

static void maps_load_collision(map_t *map, cjson_t *map_config)
{
    cjson_array_t *array = NULL;

    if (!cjson_get_prop_array(map_config, "collision_layer", &array)) {
        cjson_free(map_config);
        return;
    }
    map->collision_layer = malloc(sizeof(int *) * array->len);
    if (map->collision_layer == NULL)
        exit(84);
    maps_load_line_collision(map, array);
}

static void maps_append_data(map_t *map, cjson_t *map_config)
{
    char *back = cjson_get_prop_string_unsafe(map_config, "back");
    char *front = cjson_get_prop_string_unsafe(map_config, "front");

    map->world = cjson_get_prop_int_unsafe(map_config, "world");
    map->back = sfTexture_createFromFile(back, NULL);
    map->front = sfTexture_createFromFile(front, NULL);
    if (back)
        free(back);
    if (front)
        free(front);
}

static void maps_append(list_t *maps, cjson_t *map_config)
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
    maps_append_data(map, map_config);
    maps_load_collision(map, map_config);
    list_append(maps, node);
}

void maps_load(list_t *maps)
{
    cjson_t *maps_config = cjson_parse_file(RESSOURCES_MAPS_CONFIG);
    cjson_array_t *array = NULL;
    cjson_t *map = NULL;

    if (!maps_config)
        return;
    if (!cjson_get_prop_array(maps_config, "maps", &array)) {
        cjson_free(maps_config);
        return;
    }
    map = array->first;
    while (map) {
        maps_append(maps, map);
        map = map->next;
    }
    cjson_free(maps_config);
}
