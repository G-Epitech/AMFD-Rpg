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

void display_handle(renderer_t *renderer, app_t *app)
{
    ressources_t *ressources = renderer->ressources;
    renderer_objects_t *objects = renderer->objects;

    display_map_back(ressources->maps, objects->window, objects->sprite,
    app->world);

    display_map_front(ressources->maps, objects->window, objects->sprite,
    app->world);
    sfView_setCenter(objects->view, app->player->position);
    sfRenderWindow_setView(objects->window, objects->view);
    sfRenderWindow_display(objects->window);
}
