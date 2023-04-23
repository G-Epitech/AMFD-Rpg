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
#include "types/list/list.h"
#include "app/app.h"
#include "app/network/network.h"
#include "app/animations/animations.h"

static map_t *get_current_map(renderer_t *renderer, app_t *app)
{
    node_t *node = renderer->ressources->maps->first;
    size_t index = 0;

    while (node) {
        if (index == app->world)
            return node->data.map;
        index++;
        node = node->next;
    }
    return NULL;
}

int core_handler(renderer_t *renderer, app_t *app)
{
    map_t *current_map = get_current_map(renderer, app);

    animations_handler(renderer, app);
    if (animations_active(app->animations))
        return 1;
    if (core_tasks_handler(app, renderer) == 84)
        return 84;
    core_handle_movement(app->control, current_map->collision, app);
    core_fight_handler(app, renderer);
    core_handle_sound(app);
    core_quests(renderer, app);
    core_handle_animation(app);
    network_receive(app);
    return 0;
}
