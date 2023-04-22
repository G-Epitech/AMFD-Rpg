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
 * @brief Get item at given position on grid
 * @param inventory Inventory of player
 * @param pos Position of wanted item
 * @param active Active status of wanted item
 * @return Found item
 */
inventory_item_t * inventory_get_item_at_pos(list_t *inventory,
int pos, bool active);

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

/**
 * @brief Life inventory speed value
 * @param app App object
 * @param progress Progress object
 * @return Percentage of speed
 */
int fight_get_enemy_life(app_t *app, progress_t *progress);

/**
 * @brief Inventory set target position
 * @param inventory Inventory of player
 * @param event Event object
 */
void inventory_set_target_position(list_t *inventory,
inventory_event_t *event);

/**
 * @brief On inventory item moved prevent bad move
 * @param inventory Inventory of player
 * @param event Event object
 */
void inventory_onmove_prevent_bad(list_t *inventory,
inventory_event_t *event);

/**
 * @brief Get free position on distance i from target item of event
 * @param i Distance max to free box
 * @param inventory Inventory of player
 * @param event Event object
 * @return Status of free box availability
 */
bool inventory_onmove_get_free_positions(int i, list_t *inventory,
inventory_event_t *event);

/**
 * @brief Handler for inventory item click
 * @param app App object
 */
void inventory_onclick(app_t *app);

/**
 * @brief Event handler on item active click
 * @param app App object
 * @param item Clicked item
 */
void inventory_onclick_item_active(app_t *app, inventory_item_t *item);

/**
 * @brief Event handler on item consumable click
 * @param app App object
 * @param item Clicked item
 */
void inventory_onclick_item_consumable(app_t *app, inventory_item_t *item);

/**
 * @brief Event handler on item equipement click
 * @param app App object
 * @param item Clicked item
 */
void inventory_onclick_item_equipement(app_t *app, inventory_item_t *item);

/**
 * @brief Disable given item
 * @param player Player on which set inventory
 * @param inventory_item Inventory item to disable
 * @return Status of disabling
 */
void inventory_set_item_inactive(player_t *player,
inventory_item_t *inventory_item);

/**
 * @brief Enable given item
 * @param player Player on which set inventory
 * @param inventory_item Inventory item to enable
 * @return Status of enabling
 */
bool inventory_set_item_active(player_t *player,
inventory_item_t *inventory_item);

/**
 * @brief Apply characteritics of added and removed items on player
 * @param player Player to impact
 * @param Item Item of which apply characteritics
 * @param factor Factor of gain
 */
void inventory_item_impact_player(player_t *player,
inventory_item_t *item, int factor);

#endif /* !INVENTORY_H_ */
