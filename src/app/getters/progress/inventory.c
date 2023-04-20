/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory
*/

#include "types/components/types.h"

int inventory_get_xp(app_t *app, progress_t *progress)
{
    float ratio = (float) app->player->xp / (float) app->player->xp_max;

    (void) progress;
    return (ratio * 100);
}

int inventory_get_life(app_t *app, progress_t *progress)
{
    float ratio = (float) app->player->life / (float) app->player->life_max;

    (void) progress;
    return (ratio * 100);
}

int inventory_get_intelligence(app_t *app, progress_t *progress)
{
    float ratio = (float) app->player->intellect;

    (void) progress;
    ratio /= (float) app->player->intellect_max;
    return (ratio * 100);
}

int inventory_get_speed(app_t *app, progress_t *progress)
{
    float ratio = (float) app->player->speed / (float) app->player->speed_max;

    (void) progress;
    return (ratio * 100);
}
