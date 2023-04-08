/*
** EPITECH PROJECT, 2023
** settings.h
** File description:
** Settings functions
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

    #include "app/types.h"

typedef struct s_renderer renderer_t;
typedef struct s_lever lever_t;

/**
 * @brief Update music settings
 * @param renderer Renderer structure
 * @param app Application structure
 * @param lever Lever associate
 */
int settings_music(renderer_t *renderer, app_t *app, lever_t *lever);

/**
 * @brief Update fullscreen settings
 * @param renderer Renderer structure
 * @param app Application structure
 * @param lever Lever associate
 */
int settings_fullscreen(renderer_t *renderer, app_t *app, lever_t *lever);

/**
 * @brief Update developer settings
 * @param renderer Renderer structure
 * @param app Application structure
 * @param lever Lever associate
 */
int settings_developer(renderer_t *renderer, app_t *app, lever_t *lever);

#endif /* !SETTINGS_H_ */
