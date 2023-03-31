/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Renderer types
*/

#ifndef RENDERER_TYPES_H_
    #define RENDERER_TYPES_H_

    #include <SFML/Graphics.h>

/**
 * @brief Renderer structure
*/
typedef struct renderer {
    sfSprite *sprite;
    sfCircleShape *circle;
    sfRectangleShape *rectangle;
    sfText *text;
    sfRenderWindow *window;
} renderer_t;

#endif /* !RENDERER_TYPES_H_ */
