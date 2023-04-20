/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load
*/

#include <stdlib.h>
#include <stdbool.h>
#include "app/items/types.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"

static void set_rect(cjson_t *config, item_t *item)
{
    cjson_t *rect_config = cjson_get_prop(config, "rect");
    sfVector2i position = {0, 0};

    if (!rect_config)
        return;
    item->rect.height = ITEM_SIZE.y;
    item->rect.width = ITEM_SIZE.x;
    cjson_get_prop_int(rect_config, "x", &(position.x));
    cjson_get_prop_int(rect_config, "y", &(position.y));
    item->rect.left = ITEM_SIZE.x * position.x;
    item->rect.top = ITEM_SIZE.y * position.y;
}

static bool load_levels(cjson_t *config, item_t *item)
{
    cjson_t *levels = cjson_get_prop(config, "levels");

    if (!levels)
        return false;
    cjson_get_prop_int(levels, "intelligence", &item->intelligence);
    cjson_get_prop_int(levels, "speed", &item->speed);
    cjson_get_prop_int(levels, "life", &item->life);
    cjson_get_prop_int(levels, "xp", &item->xp);
    return true;
}

static void item_init(item_t *item)
{
    item->type = IVT_CONSUMABLE;
    item->id = 0;
    item->intelligence = 0;
    item->life = 0;
    item->price = 0;
    item->speed = 0;
    item->xp = 0;
    item->rect = (sfIntRect) {0, 0, 0, 0};
}

bool item_load(cjson_t *config, item_t **item)
{
    *item = malloc(sizeof(item_t));
    if (!item)
        return false;
    item_init(*item);
    if (!cjson_get_prop_int(config, "id", (int *)(&(*item)->id)))
        return false;
    if (!cjson_get_prop_string(config, "label", &(*item)->label))
        return false;
    if (!cjson_get_prop_int(config, "type", (int *)(&(*item)->type)))
        return false;
    if (!cjson_get_prop_float(config, "price", &(*item)->price))
        return false;
    set_rect(config, *item);
    return load_levels(config, *item);
}
