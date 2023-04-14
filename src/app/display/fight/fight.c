/*
** EPITECH PROJECT, 2023
** fight.c
** File description:
** Fight main
*/

#include "app/display/display.h"
#include "app/types.h"
#include "types/renderer/types.h"

void display_fight(renderer_t *renderer, app_t *app)
{
    if (app->state != ST_FIGHT ||
    !app->interaction->active ||
    app->interaction->type != IT_FIGHT)
        return;
    display_fight_choice(renderer, app);
}
