/*
** EPITECH PROJECT, 2023
** icon.c
** File description:
** Display button by icon
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/types.h"
#include "types/list/types.h"

void display_components_icon(renderer_t *renderer, button_t *button)
{
    renderer_objects_t *objects = renderer->objects;

    sfSprite_setTexture(objects->sprite, button->texture, sfTrue);
    sfSprite_setPosition(objects->sprite, button->position);
    sfSprite_setScale(objects->sprite, (sfVector2f) {button->scale,
    button->scale});
    sfRenderWindow_drawSprite(renderer->window, objects->sprite, NULL);
}
