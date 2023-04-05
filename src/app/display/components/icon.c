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
    sfSprite_setTexture(renderer->sprite, button->texture, sfTrue);
    sfSprite_setPosition(renderer->sprite, button->position);
    sfSprite_setScale(renderer->sprite, (sfVector2f) {button->scale,
    button->scale});
    sfRenderWindow_drawSprite(renderer->window, renderer->sprite, NULL);
}
