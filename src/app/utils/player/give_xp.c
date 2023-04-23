/*
** EPITECH PROJECT, 2023
** give_xp.c
** File description:
** Give XP to the player
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "app/animations/animations.h"
#include "my/include/my.h"

static void level_update(renderer_t *renderer, app_t *app)
{
    list_t *events = animation_event_new(app);
    int max = app->player->xp_max;
    char *description = NULL;

    app->player->xp = app->player->xp - max;
    app->player->level++;
    app->player->credits++;
    app->player->xp_max = app->player->level * 10;
    description = my_strcat("Vous venez de passer au\nniveau ",
    nbr_to_str(app->player->level));
    animations_notif_add(events, renderer->ressources->icons->xp,
    "Nouveau niveau", my_strdup(description));
    free(description);
}

void utils_give_xp(renderer_t *renderer, app_t *app, int xp)
{
    list_t *events = animation_event_new(app);
    int max = app->player->xp_max;
    char *description = NULL;

    app->player->xp += xp;
    if (app->player->xp >= max) {
        level_update(renderer, app);
    } else {
        description = my_strcat("Vous venez de gagner ", nbr_to_str(xp));
        description = my_strcat(description, " XP.");
        animations_notif_add(events, renderer->ressources->icons->xp,
        "Gain experience", my_strdup(description));
        free(description);
    }
}
