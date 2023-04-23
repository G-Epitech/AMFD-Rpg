/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** consume
*/

#include <stdlib.h>
#include <stdbool.h>
#include "app/items/types.h"

item_consumer_t item_get_consumer(item_t *item)
{
    int i = 0;
    item_consumer_t consumer = NULL;

    while (!consumer && i <= item->consumer) {
        if (i == item->consumer)
            consumer = item_consumers[i];
        i += 1;
    }
    return consumer;
}
