/*
** EPITECH PROJECT, 2023
** icon.c
** File description:
** Display button by icon
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/list/types.h"

void display_components_icon(renderer_t *renderer, button_t *button)
{
    renderer_objects_t *objects = renderer->objects;
    sfVector2u size = sfTexture_getSize(button->texture);
    sfVector2f origin = {
        ((float) size.x * (button->origin.x / 100)),
        ((float) size.y * (button->origin.y / 100))
    };
    sfVector2f position = {
        button->position.x + origin.x,
        button->position.y + origin.y
    };
    renderer_objects_reset_sprite(objects);
    sfSprite_setTexture(objects->sprite, button->texture, sfTrue);
    sfSprite_setPosition(objects->sprite, position);
    sfSprite_setOrigin(objects->sprite, origin);
    sfSprite_setScale(objects->sprite, (sfVector2f) {button->scale,
    button->scale});
    sfRenderWindow_drawSprite(renderer->window, objects->sprite, NULL);
}
