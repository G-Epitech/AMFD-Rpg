/*
** EPITECH PROJECT, 2023
** backgrounds.c
** File description:
** Display backgrounds
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/types.h"
#include "types/ressources/types.h"
#include "types/list/types.h"

static void display_background(background_t *background, renderer_t *renderer)
{
    sfSprite_setTexture(renderer->sprite, background->texture, sfTrue);
    sfSprite_setPosition(renderer->sprite, background->position);
    sfSprite_setScale(renderer->sprite, (sfVector2f) {background->scale,
    background->scale});
    sfRenderWindow_drawSprite(renderer->window, renderer->sprite, NULL);
}

void display_components_backgrounds(renderer_t *renderer, app_t *app)
{
    list_t *backgrounds = renderer->ressources->components->backgrounds;
    node_t *node = backgrounds->first;
    background_t *background = NULL;

    while (node) {
        background = node->data.background;
        if (background->app_state == app->state) {
            display_background(background, renderer);
        }
        node = node->next;
    }
}
