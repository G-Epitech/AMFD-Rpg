/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Renderer types
*/

#ifndef RENDERER_TYPES_H_
    #define RENDERER_TYPES_H_

    #include <SFML/Graphics.h>
    #include "types/components/types.h"
    #include "types/ressources/types.h"

    #define FONT_FILE "assets/font.ttf"

/**
 * @brief Renderer structure
*/
typedef struct s_renderer {
    sfSprite *sprite;
    sfCircleShape *circle;
    sfRectangleShape *rectangle;
    sfText *text;
    sfRenderWindow *window;
    sfView *view;
    const sfView *default_view;
    sfFont *font;
    components_t *components;
    ressources_t *ressources;
} renderer_t;

#endif /* !RENDERER_TYPES_H_ */
