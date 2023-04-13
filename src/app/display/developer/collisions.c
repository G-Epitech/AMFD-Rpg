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
        y = app->player->position.y + app->control[i].offset.y * 16;
        renderer_objects_reset_rectangle(renderer->objects);
        sfRectangleShape_setPosition(rectangle, (sfVector2f) {x, y});
        sfRectangleShape_setSize(rectangle, (sfVector2f) {16, 16});
        sfRectangleShape_setFillColor(rectangle, (sfColor) {0, 0, 0, 0});
        sfRectangleShape_setOutlineColor(rectangle, sfGreen);
        sfRectangleShape_setOutlineThickness(rectangle, 0.5);
        sfRenderWindow_drawRectangleShape(renderer->window, rectangle, NULL);
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

static void display_box(renderer_t *renderer,
size_t x, size_t y, sfColor color)
{
    sfRectangleShape *rectangle = renderer->objects->rectangle;
    
    sfRectangleShape_setPosition(rectangle, (sfVector2f) {x * 16, y * 16});
    sfRectangleShape_setSize(rectangle, (sfVector2f) {16, 16});
    sfRectangleShape_setFillColor(rectangle, (sfColor) {0, 0, 0, 0});
    sfRectangleShape_setOutlineColor(rectangle, color);
    sfRectangleShape_setOutlineThickness(rectangle, 0.5);
    sfRenderWindow_drawRectangleShape(renderer->window, rectangle, NULL);
}

static void display_collision(renderer_t *renderer, map_t *current_map,
size_t x, size_t y)
{
    int **collision_map = current_map->collision_layer;

    renderer_objects_reset_rectangle(renderer->objects);
    if (collision_map[y][x] == IT_WALL)
        display_box(renderer, x, y, sfRed);
    if (collision_map[y][x] == IT_NPC) {
        display_box(renderer, x, y, sfYellow);
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
    for (size_t y = 0; y < map_size.y; y++) {
        for (size_t x = 0; x < map_size.x; x++) {
            display_collision(renderer, current_map, x, y);
        }
    }
    display_collision_player(renderer, app);
    display_collision_futur(renderer, app);
}
