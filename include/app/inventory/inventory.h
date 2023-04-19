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

typedef struct s_progress progress_t;

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

/**
 * @brief Get inventory xp value
 * @param app App object
 * @param progress Progress object
 * @return Percentage of xp
 */
int inventory_get_xp(app_t *app, progress_t *progress);

/**
 * @brief Get inventory life value
 * @param app App object
 * @param progress Progress object
 * @return Percentage of life
 */
int inventory_get_life(app_t *app, progress_t *progress);

/**
 * @brief Get inventory intelligence value
 * @param app App object
 * @param progress Progress object
 * @return Percentage of intelligence
 */
int inventory_get_intelligence(app_t *app, progress_t *progress);

/**
 * @brief Get inventory speed value
 * @param app App object
 * @param progress Progress object
 * @return Percentage of speed
 */
int inventory_get_speed(app_t *app, progress_t *progress);

/**
 * @brief Event handler for button releasing on inventory
 * @param app App object
 * @param event Event object
 */
void inventory_onrelease(app_t *app, sfEvent event);

/**
 * @brief Event handler for button press on inventory
 * @param app App object
 * @param event Event object
 */
void inventory_onpress(app_t *app, sfEvent event);

/**
 * @brief Event handler for button press on inventory
 * @param app App object
 * @param event Event object
 */
void inventory_onmove(app_t *app, sfEvent event);

/**
 * @brief Get target and selected items of given event
 * @param inventory Inventory of player
 * @param event Event of inventory
 * @param selected Selected item
 * @param target Target item
 */
void inventory_get_target_and_selected(list_t *inventory,
inventory_event_t *event, inventory_item_t **selected,
inventory_item_t **target);

/**
 * @brief Swap event items
 * @param player Player object
 * @param event Event object
 */
void inventory_swap_items_on_event(player_t *player,
inventory_event_t *event);

/**
 * @brief Get mana of fight
 * @param app App object
 * @param progress Progress object
 * @return Percentage of speed
 */
int fight_get_mana(app_t *app, progress_t *progress);

/**enemy lifeinventory speed value
 * @param app App object
 * @param progress Progress object
 * @return Percentage of speed
 */
int fight_get_enemy_life(app_t *app, progress_t *progress);

#endif /* !INVENTORY_H_ */
