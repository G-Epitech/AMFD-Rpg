/*
** EPITECH PROJECT, 2023
** core.h
** File description:
** Core functions
*/

#ifndef CORE_H_
    #define CORE_H_

    #include "app/types.h"
    #include "app/app.h"
    #include "types/players/players.h"
    #include "types/renderer/types.h"

/**
 * @brief Main function for the movement of the player
 * @param player Player controlled by the user
 * @param control Controller structure that will help
 * player move
 * @param collision_layer Layer of collisions
*/
void core_handle_movement(control_t *control, sfImage *collision, app_t *app);
/**
 * @brief Function that will handle the core actions of the
 * game
 * @param renderer Main renderer structure
 * @param app Main app structure
*/
int core_handler(renderer_t *renderer, app_t *app);

#endif /* !CORE_H_ */
