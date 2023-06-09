/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include "app/types.h"

typedef struct s_renderer renderer_t;
typedef struct s_button button_t;

/**
 * @brief Test function
*/
int test(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Give XP to a player
 * @param renderer Renderer object
 * @param app App object
 * @param xp Experiences to give
 */
void utils_give_xp(renderer_t *renderer, app_t *app, int xp);

#endif /* !UTILS_H_ */
