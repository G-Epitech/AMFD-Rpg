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
*/
void renderer_destroy(renderer_t *renderer);

/**
 * @brief Loads the components ressources, view in renderer
 * while also displaying what's loading on the screen
*/
void load_renderer(renderer_t *renderer);

#endif /* !RENDERER_H_ */
