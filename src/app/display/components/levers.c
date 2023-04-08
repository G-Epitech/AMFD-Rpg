/*
** EPITECH PROJECT, 2023
** levers.c
** File description:
** Display levers components
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/list/types.h"

static void display_lever(lever_t *lever, renderer_t *renderer)
{
    sfSprite *sprite = renderer->objects->sprite;
    components_r_t *components = renderer->ressources->components;

    renderer_objects_reset_sprite(renderer->objects);
    if (lever->active)
        sfSprite_setTexture(sprite, components->lever->on, sfTrue);
    else
        sfSprite_setTexture(sprite, components->lever->off, sfTrue);
    sfSprite_setPosition(sprite, lever->position);
    sfSprite_setScale(sprite, (sfVector2f) {lever->scale, lever->scale});
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
}

void display_components_levers(renderer_t *renderer, app_t *app)
{
    list_t *levers = renderer->components->levers;
    node_t *node = levers->first;
    lever_t *lever = NULL;

    while (node) {
        lever = node->data.lever;
        if (app->state != lever->app_state) {
            node = node->next;
            continue;
        }
        display_lever(lever, renderer);
        node = node->next;
    }
}
