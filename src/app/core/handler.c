/*
** EPITECH PROJECT, 2023
** handler.c
** File description:
** Handle core
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "types/players/players.h"
#include "app/core/core.h"
#include "types/list/types.h"
#include "app/app.h"

void core_handler(renderer_t *renderer, app_t *app)
{
    core_handle_movement(app->player, app->control,
    renderer->ressources->maps->first->data.map->collision_layer);
}
