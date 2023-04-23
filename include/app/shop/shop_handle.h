/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Shop functions
*/

#ifndef SHOP_HANDLE_H_
    #define SHOP_HANDLE_H_

    #define PLAYER_SHOPING(state) ((state) == (IT_SHOP) ? (1) : (0))

/**
 * @brief Handles player shopping
 * @param app App object
*/
void shop_handler(app_t *app);

#endif /* !SHOP_HANDLE_H_ */
