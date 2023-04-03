/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** renderer
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "types/view/view.h"

renderer_objects_t renderer_objects_init(sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfText *text = sfText_create();
    sfCircleShape *circle = sfCircleShape_create();
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfView *view = view_init();
    renderer_objects_t objects = {  window, view, sprite, text,
                                    circle, rectangle  };

    return (objects);
}

void renderer_objects_free(renderer_objects_t *objects)
{
    if (objects) {
        sfSprite_destroy(objects->sprite);
        sfText_destroy(objects->text);
        sfCircleShape_destroy(objects->circle);
        sfRectangleShape_destroy(objects->rectangle);
        sfView_destroy(objects->view);
    }
}
