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
 * @brief Main function for the sound system
 * @param app Main app structure
*/
void core_handle_sound(app_t *app);

/**
 * @brief Function that will handle the core actions of the
 * game
 * @param renderer Main renderer structure
 * @param app Main app structure
*/
int core_handler(renderer_t *renderer, app_t *app);

/**
 * @brief Interactions of NPCs
 * @param id Id of the NPC
 * @param app Application structure
 */
void core_interactions_npc(sfColor pixel, app_t *app);

/**
 * @brief Animations of the game
 * @param app App of object
 * @param renderer Renderer object
*/
void core_handle_animation(app_t *app);

/**
 * @brief Enemy fight
 * @param app App object
 */
void core_fight_enemy(app_t *app, renderer_t *renderer);

/**
 * @brief handle fight core
 * @param app App object
 */
void core_fight_handler(app_t *app, renderer_t *renderer);

/**
 * @brief Detects color interaction
 * @param pixel Current color near the player
 * @param interaction_color Color to check
 * @return True if color is the right one, false if not
*/
bool core_interaction_detect_color(sfColor pixel, sfColor interaction_color);

/**
 * @brief Interactions at exit or entry
 * @param pixel Pixel near the player
 * @param app App object
*/
void core_interactions_travel(sfColor pixel, app_t *app);

/**
 * @brief Handles traveling
 * @param renderer Renderer object
 * @param app App object
 * @param curr_map Current map
*/
void core_handle_travel(renderer_t *renderer, app_t *app, map_t *curr_map);

/**
 * @brief handle quests core
 * @param app App object
 */
void core_quests(app_t *app);

/**
 * @brief handle shop interactions
 * @param pixel Pixel near the player
 * @param app App object
*/
void core_interactions_shop(sfColor pixel, app_t *app);

#endif /* !CORE_H_ */
