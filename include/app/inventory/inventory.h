/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #include "app/types.h"
    #include "app/items/types.h"
    #include "app/inventory/types.h"

int inventory_close(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Create a new inventory item
 * @param item Item to
 * @return Created inventory item
 */
inventory_item_t *inventory_item_new(item_t *target_item);

/**
 * @brief Free a given inventory item
 * @param inventory_item Inventory item to free
 */
void inventory_item_free(inventory_item_t *inventory_item);

/**
 * @brief Add item in given player inventory
 * @param player Player of which set inventory
 * @param target_item Target item to add in inventory
 * @return Adding success status
 */
bool inventory_add_item(player_t *player, item_t *target_item);

/**
 * @brief Remove item of given player inventory
 * @param player Player of which set inventory
 * @param inventory_item Inventory item to remove
 */
void inventory_remove_item(player_t *player,
inventory_item_t *inventory_item);

#endif /* !INVENTORY_H_ */
