/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** fight
*/

#include "types/components/types.h"

int fight_get_mana(app_t *app, progress_t *progress)
{
    (void) progress;
    return app->interaction->data.fight->mana * 100 / 50;
}

int fight_get_enemy_life(app_t *app, progress_t *progress)
{
    (void) app;
    (void) progress;
    return app->interaction->data.fight->enemy_life * 100 /
    app->interaction->data.fight->npc->enemy->life;
}
