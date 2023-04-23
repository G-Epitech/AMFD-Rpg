/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** renderer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "types/view/view.h"
#include "types/renderer/types.h"

renderer_objects_t *renderer_objects_init(sfRenderWindow *window)
{
    renderer_objects_t *objects = malloc(sizeof(renderer_objects_t));

    if (!objects)
        return NULL;
    objects->sprite = sfSprite_create();
    objects->text = sfText_create();
    objects->circle = sfCircleShape_create();
    objects->rectangle = sfRectangleShape_create();
    objects->window = window;
    objects->font = NULL;
    return objects;
}

void renderer_objects_free(renderer_objects_t *objects)
{
    if (objects) {
        sfSprite_destroy(objects->sprite);
        sfText_destroy(objects->text);
        sfCircleShape_destroy(objects->circle);
        sfRectangleShape_destroy(objects->rectangle);
    }
    free(objects);
}
