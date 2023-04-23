/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include <stdlib.h>
#include "app/app.h"
#include "types/list/types.h"
#include "cjson/include/cjson.h"

static void append_item(inventory_item_t *item, cjson_array_t *array)
{
    cjson_t *export = cjson_new(NULL);

    if (!export)
        return;
    cjson_set_prop(export, "id",
    CJSON_NUMBER(item->target->id), CJSON_NUMBER_T);
    cjson_set_prop(export, "active",
    CJSON_BOOL(item->active), CJSON_BOOL_T);
    cjson_array_append(array, export);
}

static void fill_inventory(list_t *inventory, cjson_array_t *array)
{
    node_t *node = inventory ? inventory->first : NULL;
    inventory_item_t *item = NULL;

    while (node) {
        item = node->data.inventory_item;
        append_item(item, array);
        node = node->next;
    }
}

void save_export_inventory(list_t *inventory, cjson_t *export)
{
    cjson_array_t *array = cjson_array_new();

    if (!array)
        return;
    fill_inventory(inventory, array);
    cjson_set_prop(export, "inventory", CJSON(array), CJSON_ARRAY_T);
}
