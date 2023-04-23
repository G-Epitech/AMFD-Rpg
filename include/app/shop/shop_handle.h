/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Shop functions
*/

#ifndef SHOP_HANDLE_H_
    #define SHOP_HANDLE_H_

    #define PLAYER_SHOPING(state) ((state) == (IT_SHOP) ? (1) : (0))
    #define GRID_POS (sfVector2f) {600, 650}
    #define GRID_NEXT_POS_OFFSET 100
    #define GRID_BASIC_RECT (sfIntRect) {0, 0, 85, 85}
    #define GRID_ACTIVE_RECT (sfIntRect) {0, 255, 85, 85}
    #define SHOP_NAME_POS (sfVector2f) {400, 250}
    #define SHOP_PLAYER_GOLD_VALUE_POS (sfVector2f) {480, 830}

    #include "app/app.h"

typedef struct s_render_objects renderer_objects_t;

/**
 * @brief Handles player shopping
 * @param app App object
*/
void shop_handler(app_t *app);

/**
 * @brief Loads items in shop stock
 * @param app App object
*/
bool load_items_stock(app_t *app);

/**
 * @brief Displays shop info
 * @param shop Current sho
 * @param objects Renderer objects
 * @param window Window
 * @param player_gold Player gold
 */
void display_shop_info(shop_t *shop, renderer_objects_t *objects,
sfRenderWindow *window, int player_gold);

/**
 * @brief Displays shop interface
 * @param shops Shop list
 * @param curr_shop_id Current id of the shop
 * @param renderer Renderer
 */
void display_shop_interface(list_t *shops, int curr_shop_id, int player_gold,
renderer_t *renderer);

/**
 * @brief Event for buying items
 * @param app App object
 * @param event Event object
*/
void buy_item(app_t *app, sfEvent event);


#endif /* !SHOP_HANDLE_H_ */
