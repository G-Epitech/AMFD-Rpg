/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"

void core_handler(renderer_t *renderer, app_t *app)
{
    task(renderer, app);
}
