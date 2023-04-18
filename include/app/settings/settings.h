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

/**
 * @brief Update volume settings
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Button associate
 */
int settings_volume_malus(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Update volume settings
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Button associate
 */
int settings_volume_up(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Update volume settings
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Button associate
 */
int settings_fps_malus(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Update volume settings
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Button associate
 */
int settings_fps_up(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Update a lower resolution (820x600)
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Button associate
 */
int settings_resolution_lower(renderer_t *renderer,
app_t *app, button_t *button);

/**
 * @brief Update a medium resolution (1920x1080)
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Button associate
 */
int settings_resolution_medium(renderer_t *renderer,
app_t *app, button_t *button);

/**
 * @brief Update a high resolution (2560x1600)
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Button associate
 */
int settings_resolution_high(renderer_t *renderer,
app_t *app, button_t *button);

#endif /* !SETTINGS_H_ */
