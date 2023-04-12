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

static void display_collision_box(renderer_t *renderer, map_t *current_map,
size_t x, size_t y)
{
    int **collision_map = current_map->collision_layer;
    sfRectangleShape *rectangle = renderer->objects->rectangle;

    renderer_objects_reset_rectangle(renderer->objects);
    if (collision_map[y][x] == 1) {
        sfRectangleShape_setPosition(rectangle, (sfVector2f) {x * 16, y * 16});
        sfRectangleShape_setSize(rectangle, (sfVector2f) {16, 16});
        sfRectangleShape_setFillColor(rectangle, (sfColor) {0, 0, 0, 0});
        sfRectangleShape_setOutlineColor(rectangle, sfRed);
        sfRectangleShape_setOutlineThickness(rectangle, 0.5);
        sfRenderWindow_drawRectangleShape(renderer->window, rectangle, NULL);
    }
}

void display_developer_collisions(renderer_t *renderer, app_t *app)
{
    map_t *current_map = renderer->ressources->maps->first->data.map;
    sfVector2u map_size = sfTexture_getSize(current_map->back); 

    map_size.x /= 16;
    map_size.y /= 16;
    if (!app->settings->developer)
        return;
    for (size_t y = 0; y < map_size.y; y++)
    {
        for (size_t x = 0; x < map_size.x; x++)
        {
            display_collision_box(renderer, current_map, x, y);
        }
    }
    display_collision_player(renderer, app);
}
