/*
** EPITECH PROJECT, 2023
** RPG [WSL: Ubuntu]
** File description:
** Functions for the shop
*/

#ifndef SHOP_H_
    #define SHOP_H_

    #define SHOP_CONFIG "configs/shops.json"
    #define GRID_FILE "assets/inventory/grid.png"
    #define SMALL_COIN_FILE "assets/components/icons/small_coin.png"
    #define ITEMS_MAX 8

typedef struct s_list list_t;

/**
 * @brief Loads shops
 * @return List of shops
*/
list_t *load_shop(renderer_t *renderer);

/**
 * @brief Includes shops on the map
 * @param renderer Renderer object
 * @param shops List of shops
*/
void shop_include_to_array(renderer_t *renderer, list_t *shops);
#endif /* !SHOP_H_ */
