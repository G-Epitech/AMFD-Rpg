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

static void display_elements(renderer_t *renderer, app_t *app)
{
    display_components(renderer, app);
    display_menus(renderer, app);
    display_tasks_handler(renderer, app);
    display_developer_position(renderer, app);
    display_animations(renderer, app);
    display_dialogs(renderer, app);
    display_hud(renderer, app);
    display_dialog_box(renderer, app->dialog_box);
}

static void center_view(renderer_t *renderer, app_t *app)
{
    sfVector2f center = app->player->position;

    center.x += 8;
    center.y += 16;
    sfView_setCenter(renderer->map_view, center);
}

void display_handler(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    sfRenderWindow_clear(renderer->window, sfBlack);
    sfRenderWindow_setView(renderer->window, renderer->map_view);
    display_game(renderer, app);
    center_view(renderer, app);
    sfRenderWindow_setView(objects->window, renderer->default_view);
    display_elements(renderer, app);
    sfRenderWindow_display(renderer->window);
}
