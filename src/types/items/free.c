/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** free
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "app/items/items.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"
#include "types/ressources/ressources.h"

void items_free(list_t *items)
{
    node_t *node = items ? items->first : NULL;
    item_t *item = NULL;

    while (node) {
        item = node->data.item;
        free(item->label);
        node = node->next;
    }
    list_free(items);
    return;
}
