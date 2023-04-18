/*
** EPITECH PROJECT, 2023
** interaction.c
** File description:
** Display interaction icon
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "app/display/types.h"
#include "types/renderer/renderer.h"
#include "types/list/types.h"

void display_components_interaction(renderer_t *renderer, app_t *app)
{
    sfSprite *sprite = renderer->objects->sprite;

    if (app->interaction->interaction && !app->interaction->active) {
        renderer_objects_reset_sprite(renderer->objects);
        sfSprite_setPosition(sprite, INTERACTION_ICON_POSITION);
        sfSprite_setTexture(sprite, renderer->ressources->icons->interaction,
        sfTrue);
        sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    }
}
