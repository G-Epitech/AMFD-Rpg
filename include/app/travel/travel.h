/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Travel functions
*/

#ifndef TRAVEL_H_
    #define TRAVEL_H_

    #define PLAYER_TRAVELING(state) ((state) == (IT_TRAVEL) ? (1) : (0))

typedef struct s_map map_t;

/**
 * @brief Gets the current map
 * @param renderer Renderer object
 * @param app App object
 * @return Current map
*/
map_t *get_current_map(renderer_t *renderer, app_t *app);

/**
 * @brief Exits current map
 * @param app App object
 * @param renderer Renderer object
 * @param curr_map Current map
*/
void travel_exit(app_t *app, renderer_t *renderer, map_t *curr_map);

/**
 * @brief Enters next map
 * @param app App object
 * @param renderer Renderer object
 * @param curr_map Current map
*/
void travel_enter(app_t *app, renderer_t *renderer, map_t *curr_map);


#endif /* !TRAVEL_H_ */
