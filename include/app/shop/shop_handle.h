/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Shop functions
*/

#ifndef SHOP_HANDLE_H_
    #define SHOP_HANDLE_H_

    #define PLAYER_SHOPING(state) ((state) == (IT_SHOP) ? (1) : (0))
    #define GRID_POS (sfVector2f) {600, 700}
    #define GRID_NEXT_POS_OFFSET 100
    #define GRID_BASIC_RECT (sfIntRect) {0, 0, 85, 85}

/**
 * @brief Handles player shopping
 * @param app App object
*/
void shop_handler(app_t *app);

#endif /* !SHOP_HANDLE_H_ */
