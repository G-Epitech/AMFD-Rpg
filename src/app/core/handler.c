/*
** EPITECH PROJECT, 2023
** handler.c
** File description:
** Handle core
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/types.h"
#include "types/players/players.h"
#include "app/core/core.h"
#include "types/list/types.h"
#include "app/app.h"
#include "app/network/network.h"
#include "app/animations/animations.h"

int core_handler(renderer_t *renderer, app_t *app)
{
    map_t *current_map = renderer->ressources->maps->first->data.map;

    if (PLAYER_IN_ANIM(app->animations)) {
        animations_handler(renderer, app);
        return 1;
    }
    if (core_tasks_handler(app) == 84)
        return 84;
    core_handle_movement(app->control, current_map->collision, app);
    core_fight_handler(app, renderer);
    core_handle_sound(app);
    core_handle_animation(app, renderer);
    network_receive(app);
    return 0;
}
