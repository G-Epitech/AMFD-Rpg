/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** Functions for the in game menu
*/

#ifndef IN_GAME_MENU_H_
    #define IN_GAME_MENU_H_

    #include "app/app.h"

/**
 * @brief Updates the previous state
 * @param app App object
*/
void update_prev_app_state(app_t *app);

/**
 * @brief Exits the in game menu back to the game
 * @param renderer Renderer object
 * @param app App object
 * @param button Button object
*/
int in_game_menu_exit(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Takes the user back to the title screen and restarts app
 * @param renderer Renderer object
 * @param app App object
 * @param button Button object
*/
int in_game_menu_exit_to_title(renderer_t *renderer, app_t *app,
button_t *button);

/**
 * @brief Restarts the session when exiting to title
 * @param app App object
*/
void restart_session(app_t *app);

/**
 * @brief Restarts a player
 * @param player Player
*/
void restart_player(player_t *player);

#endif /* !IN_GAME_MENU_H_ */
