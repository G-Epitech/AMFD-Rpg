/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory
*/

#include "types/components/types.h"

int inventory_get_xp(app_t *app, progress_t *progress)
{
    (void) app;
    (void) progress;
    return 68;
}

int inventory_get_life(app_t *app, progress_t *progress)
{
    (void) progress;
    return app->player->life * 100 / 20;
}

int inventory_get_intelligence(app_t *app, progress_t *progress)
{
    (void) app;
    (void) progress;
    return app->player->intellect * 100 / 10;
}

int inventory_get_speed(app_t *app, progress_t *progress)
{
    (void) progress;
    return app->player->speed * 100 / 10;
}
