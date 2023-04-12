/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle the display of the map
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/list/list.h"
#include "types/renderer/renderer.h"
#include "app/tasks/types.h"
#include "app/tasks/task.h"

static void display_game(renderer_t *renderer, app_t *app)
{
    ressources_t *ressources = renderer->ressources;
    renderer_objects_t *objects = renderer->objects;

    if (app->state >= ST_INGAME) {
        renderer_objects_reset_sprite(objects);
        display_map_back(ressources->maps, renderer->window, objects->sprite,
        app->world);
        display_npcs_of_world(renderer, app->npcs, app->world);
        display_player(renderer, app);
        display_map_front(ressources->maps, objects->window, objects->sprite,
        app->world);
        display_developer_collisions(renderer, app);
    }
}

void display_handler(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    sfRenderWindow_clear(renderer->window, sfBlack);
    sfRenderWindow_setView(renderer->window, renderer->map_view);
    display_game(renderer, app);
    sfView_setCenter(renderer->map_view, app->player->position);
    sfRenderWindow_setView(objects->window, renderer->default_view);
    display_components(renderer, app);
    display_menus(renderer, app);
    display_tasks_handler(renderer, app);
    sfRenderWindow_display(renderer->window);
}
