/*
** EPITECH PROJECT, 2023
** handler.c
** File description:
** Handle core
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/types.h"
#include "types/players/players.h"
#include "app/core/core.h"
#include "types/list/types.h"
#include "app/app.h"
#include "app/network/network.h"

int core_handler(renderer_t *renderer, app_t *app)
{
    map_t *current_map = renderer->ressources->maps->first->data.map;

    if (core_tasks_handler(app) == 84)
        return 84;
    core_handle_movement(app->control, current_map->collision, app);
    network_receive(app);
    return 0;
}
