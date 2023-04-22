/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** Draws the entries on the collision map
*/

#include <stdio.h>
#include "app/types.h"
#include "types/renderer/types.h"
#include "types/list/types.h"

static void insert_entry(entry_t *entry, sfImage *collision)
{
    float x_offset = 16;
    float y_offset = 16;
    sfColor color = sfBlue;

    if (entry->direction == 1)
        y_offset = entry->tile_size * 16;
    if (entry->direction == 2)
        x_offset = entry->tile_size * 16;
    color.a = (sfUint8) (255 - entry->id);
    for (size_t y = 0; y < y_offset; y++) {
        for (size_t x = 0; x < x_offset; x++) {
            sfImage_setPixel(collision,
            x + entry->pos.x,
            y + entry->pos.y,
            color);
        }
    }
}

static void include_data(entry_t *entry, map_t *map)
{
    if (entry->direction != 1 && entry->direction != 2)
        return;
    insert_entry(entry, map->collision);
    map->col_texture = sfTexture_createFromImage(map->collision, NULL);
}

void entry_include_to_array(list_t *map_list)
{
    node_t *maps = map_list->first;
    node_t *entries = NULL;
    map_t *map = NULL;
    entry_t *entry = NULL;

    (void) entries,
    (void) entry;
    if (!maps)
        return;
    while (maps) {
        map = maps->data.map;
        entries = map->entry->first;
        while (entries) {
            entry = entries->data.entry;
            include_data(entry, map);
            entries = entries->next;
        }
        maps = maps->next;
    }
}
