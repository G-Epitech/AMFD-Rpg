/*
** EPITECH PROJECT, 2023
** renderer.h
** File description:
** Renderer functions
*/

#ifndef RENDERER_H_
    #define RENDERER_H_

    #include "types.h"

/**
 * @brief Init a renderer structure
*/
renderer_t *renderer_init(void);

/**
 * @brief Destroy a renderer structure
 * @param renderer Renderer to destroy
*/
void renderer_destroy(renderer_t *renderer);

/**
 * @brief Init renderer objects
 * @param window Current window reference to insert in objects
 * @return Created set of objects
 */
renderer_objects_t *renderer_objects_init(sfRenderWindow *window);

/**
 * @brief Destroy given renderer objects
 * @param objects Objects to destroy
 */
void renderer_objects_destroy(renderer_objects_t *objects);

/**
 * @brief Reset the sprite object to default values
 * @param objects Objects to reset
 */
void renderer_objects_reset_sprite(renderer_objects_t *objects);

/**
 * @brief Reset the text object to default values
 * @param objects Objects to reset
 */
void renderer_objects_reset_text(renderer_objects_t *objects);

/**
 * @brief Reset the circle object to default values
 * @param objects Objects to reset
 */
void renderer_objects_reset_circle(renderer_objects_t *objects);

/**
 * @brief Reset the rectangle object to default values
 * @param objects Objects to reset
 */
void renderer_objects_reset_rectangle(renderer_objects_t *objects);

/**
 * @brief Reset the view object to default values
 * @param objects Objects to reset
 */
void renderer_objects_reset_view(renderer_objects_t *objects);

#endif /* !RENDERER_H_ */
