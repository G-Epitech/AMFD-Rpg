/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle the display of the map
*/

#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/types.h"

void display_handle(renderer_t *renderer, app_t *app)
{
    ressources_t *ressoruces = renderer->ressources;

    display_map_back(ressoruces->maps, renderer->window, renderer->sprite,
    app->world);
    sfRectangleShape_setPosition(renderer->rectangle, app->player->position);
    sfRectangleShape_setSize(renderer->rectangle, (sfVector2f) {6, 6});
    display_map_front(ressoruces->maps, renderer->window, renderer->sprite,
    app->world);
    sfView_setCenter(renderer->view, app->player->position);
    sfRenderWindow_setView(renderer->window, renderer->view);
    sfRenderWindow_drawRectangleShape(renderer->window, renderer->rectangle,
    NULL);
    sfRenderWindow_display(renderer->window);
}
