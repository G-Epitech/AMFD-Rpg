/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** Functions relating to the animations
*/

#ifndef ANIMATION_H_
    #define ANIMATION_H_

    #include "type.h"

/**
 * @brief Function working with core to animate the player
 * @param app App object
 * @param renderer Renderer object
*/
void animate_player(app_t *app);

/**
 * @brief Get the animation object that corresponds to the
 * current state of the playr
 * @param skin_id Player skin id
 * @param player_state Current player state
 * @param animations Player animations list
 * @return Animation
*/
animation_t *player_anim_get(int skin_id, enitity_state_t player_state,
list_t *animations);

#endif /* !ANIMATION_H_ */
