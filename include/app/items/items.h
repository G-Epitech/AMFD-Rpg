/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** items
*/

#ifndef ITEMS_H_
    #define ITEMS_H_

    #include "app/items/types.h"
    #include "types/list/list.h"
    #include "cjson/include/cjson.h"


/**
 * @brief Load all items of game
 * @return Loaded items
 */
list_t *items_load(void);

/**
 * @brief Free all given items
 * @param items List of items to free
 */
void items_free(list_t *items);

/**
 * @brief Load item from config
 * @param config Configuration of item
 * @param item Item in which import config
 * @return Status of loading success
 */
bool item_load(cjson_t *config, item_t **item);

/**
 * @brief Get consumer of given item
 * @param item Item to consume
 * @return Found consumer or NULL if not found or not set
 */
item_consumer_t item_get_consumer(item_t *item);

#endif /* !ITEMS_H_ */
