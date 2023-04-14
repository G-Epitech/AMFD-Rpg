/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_

    #include <SFML/Graphics.h>
    #include "app/animations/types.h"

typedef struct s_renderer renderer_t;
typedef struct s_app app_t;
typedef struct s_list list_t;

/**
 * @brief Animation handler
 * @param renderer Renderer object
 * @param app App object
 */
void animations_handler(renderer_t *renderer, app_t *app);

/**
 * @brief Add new animation event group
 * @param app App object
 * @return list_t* List of events
 */
list_t *animation_event_new(app_t *app);

/**
 * @brief Screen zoom animation
 * @param zoom Data of the animation event
 * @param clock Clock of animations
 * @return If the animation is ended
 */
bool animations_screen_zoom(animation_event_zoom_t *zoom, sfClock *clock);

/**
 * @brief Add new zoom animation
 * @param events Group of animations
 * @param view 
 * @param speed 
 * @param zoom 
 */
void animations_screen_zoom_add(list_t *events, sfView *view, float speed,
float zoom);

/**
 * @brief Init zoom event data
 * @return animation_event_zoom_t* Zoom event data
 */
animation_event_zoom_t *animations_screen_zoom_init(void);

#endif /* !ANIMATIONS_H_ */
