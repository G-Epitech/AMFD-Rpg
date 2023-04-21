/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Travel functions
*/

#ifndef TRAVEL_H_
    #define TRAVEL_H_

    #define EXIT_COLOR sfColor_fromRGBA(224, 112, 112, 255)
    #define PLAYER_ON_EXIT(state) ((state) == (IT_EXIT) ? (1) : (0))

typedef struct s_map map_t;

/**
 * @brief Detects travel exit
 * @param pixel Pixel surrounding
 * @param app App object
 * @param renderer Renderer object
 * @param curr_map Current map
*/
void travel_exit(app_t *app, renderer_t *renderer, map_t *curr_map);

#endif /* !TRAVEL_H_ */
