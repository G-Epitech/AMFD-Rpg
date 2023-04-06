/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle the display of the map
*/

#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/list/list.h"
#include "types/renderer/types.h"
#include "app/tasks/types.h"
#include "app/tasks/task.h"

void display_handle(renderer_t *renderer, app_t *app)
{
    ressources_t *ressources = renderer->ressources;
    renderer_objects_t *objects = renderer->objects;

    sfRenderWindow_clear(renderer->window, sfBlack);
    sfRenderWindow_setView(renderer->window, renderer->map_view);
    display_map_back(ressources->maps, renderer->window, objects->sprite,
    app->world);
    display_npcs_of_world(renderer, app->npcs, app->world);
    display_player(renderer, app->player);
    display_map_front(ressources->maps, objects->window, objects->sprite,
    app->world);
    sfView_setCenter(renderer->map_view, app->player->position);
    sfRenderWindow_setView(objects->window, renderer->default_view);
    display_components(renderer, app);
    display_tasks_handler(renderer, app);
    sfRenderWindow_display(renderer->window);
}
