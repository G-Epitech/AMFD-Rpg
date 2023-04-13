/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "app/items/items.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"
#include "types/ressources/ressources.h"

static void load_items_from_array(cjson_array_t *array, list_t *items)
{
    cjson_t *config = array ? array->first : NULL;
    item_t *item = NULL;
    node_t *node = NULL;

    while (config) {
        if (!item_load(config, &item)) {
            config = config->next;
            continue;
        }
        node = node_new((node_data_t) item);
        if (node)
            list_append(items, node);
        config = config->next;
    }
}

list_t *items_load(void)
{
    list_t *items = list_new();
    cjson_t *config = cjson_parse_file(ITEMS_CONFIG);
    cjson_array_t *array = NULL;

    if (!config || ! items) {
        list_free(items);
        cjson_free(config);
        return NULL;
    }
    if (!cjson_get_prop_array(config, "items", &array)) {
        list_free(items);
        cjson_free(config);
        return NULL;
    }
    load_items_from_array(array, items);
    cjson_free(config);
    return items;
}
