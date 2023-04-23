/*
** EPITECH PROJECT, 2023
** RPG [WSL: Ubuntu]
** File description:
** Functions for the shop
*/

#ifndef SHOP_H_
    #define SHOP_H_

    #define SHOP_CONFIG "configs/shops.json"

typedef struct s_list list_t;

/**
 * @brief Loads shops
 * @return List of shops
*/
list_t *load_shop(void);
#endif /* !SHOP_H_ */
