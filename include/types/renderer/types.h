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

//Set of objects used in rendering phasis
typedef struct s_render_objects {
    sfRenderWindow *window;
    sfSprite *sprite;
    sfText *text;
    sfCircleShape *circle;
    sfRectangleShape *rectangle;
} renderer_objects_t;

/**
 * @brief Renderer structure
*/
typedef struct s_renderer {
    sfFont *font;
    sfRenderWindow *window;
    components_t *components;
    ressources_t *ressources;
    sfView *map_view;
    const sfView *default_view;
    renderer_objects_t *objects;
} renderer_t;

#endif /* !RENDERER_TYPES_H_ */
