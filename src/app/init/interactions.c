/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** settings
*/


#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/types.h"

bool app_init_interactions(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    app->interaction = malloc(sizeof(interactions_t));
    if (!app->interaction)
        return false;
    app->interaction->interaction = false;
    app->interaction->active = false;
    app->interaction->type = IT_NULL;
    return true;
}
