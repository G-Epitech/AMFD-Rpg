/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** renderer
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"

void renderer_objects_destroy(renderer_objects_t *objects)
{
    if (objects) {
        sfSprite_destroy(objects->sprite);
        sfText_destroy(objects->text);
        sfCircleShape_destroy(objects->circle);
        sfRectangleShape_destroy(objects->rectangle);
        sfView_destroy(objects->view);
    }
}
