/*
** EPITECH PROJECT, 2023
** collisions.c
** File description:
** Display collisions of the map
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "types/list/list.h"

static void display_collision_futur(renderer_t *renderer, app_t *app)
{
    int x = 0;
    int y = 0;
    sfRectangleShape *rectangle = renderer->objects->rectangle;

    for (size_t i = 0; i < 4; i++) {
        x = app->player->position.x + app->control[i].offset.x * 16;
        y = app->player->position.y + app->control[i].offset.y * 16 + 16;
        x = (int) (x / 16) * 16;
        y = (int) (y / 16) * 16;
        renderer_objects_reset_rectangle(renderer->objects);
        sfRectangleShape_setPosition(rectangle, (sfVector2f) {x, y});
        sfRectangleShape_setSize(rectangle, (sfVector2f) {16, 16});
        sfRectangleShape_setFillColor(rectangle, (sfColor) {0, 0, 0, 0});
        sfRectangleShape_setOutlineColor(rectangle, sfGreen);
        sfRectangleShape_setOutlineThickness(rectangle, 0.5);
        sfRenderWindow_drawRectangleShape(renderer->window, rectangle, NULL);
    }
}

static void display_collisions_map(renderer_t *renderer, app_t *app)
{
    node_t *node = renderer->ressources->maps->first;
    map_t *map = NULL;

    while (node) {
        map = node->data.map;
        if (app->world == map->world) {
            sfSprite_setTexture(renderer->objects->sprite, map->col_texture,
            sfTrue);
            sfRenderWindow_drawSprite(renderer->window,
            renderer->objects->sprite, NULL);
        }
        node = node->next;
    }
}

static void display_collision_player(renderer_t *renderer, app_t *app)
{
    sfRectangleShape *rectangle = renderer->objects->rectangle;
    sfVector2f position = app->player->position;

    renderer_objects_reset_rectangle(renderer->objects);
    sfRectangleShape_setPosition(rectangle, (sfVector2f) {position.x + 2,
    position.y + 20});
    sfRectangleShape_setSize(rectangle, (sfVector2f) {12, 12});
    sfRectangleShape_setFillColor(rectangle, (sfColor) {0, 0, 0, 0});
    sfRectangleShape_setOutlineColor(rectangle, sfBlue);
    sfRectangleShape_setOutlineThickness(rectangle, 0.5);
    sfRenderWindow_drawRectangleShape(renderer->window, rectangle, NULL);
}

void display_developer_collisions(renderer_t *renderer, app_t *app)
{
    if (!app->settings->developer)
        return;
    display_collision_player(renderer, app);
    display_collision_futur(renderer, app);
    display_collisions_map(renderer, app);
}
