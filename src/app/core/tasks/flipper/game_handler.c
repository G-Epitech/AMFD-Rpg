/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/flipper/flipper.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "types/list/list.h"
#include "app/animations/animations.h"

static void time_handler(app_t *app, int *time_mili_int)
{
    task_t *node = find_task_node(app, 3);

    TIME(node->content.flipper) =
    sfClock_getElapsedTime(CLOCK(node->content.flipper));
    TIME_FLOAT(node->content.flipper) =
    TIME(node->content.flipper).microseconds / (SECOND_MICRO);
    (*time_mili_int) =
    (int) TIME(node->content.flipper).microseconds / SECOND_MILI;
}

static void game_result(app_t *app, int *prev_sec,
int *prev_mili_sec, renderer_t *renderer)
{
    task_t *node = find_task_node(app, 3);
    list_t *events = NULL;

    if (NB_LIFE_FLIPPER(node) <= 0) {
        events = animation_event_actual(app);
        animations_notif_add(events, renderer->ressources->icons->hungry,
        "Flipper", "Vous n'avez pas reussi à utiliser le flipper.");
        reset_setup_flipper(app, prev_sec, prev_mili_sec);
        app->state = ST_INGAME;
        app->interaction->active = false;
    }
    if (NB_CIRCLE_HIT(node) == NB_CIRCLE_FLIPPER(node)) {
        events = animation_event_actual(app);
        animations_notif_add(events, renderer->ressources->icons->happy,
        "Flipper", "Vous avez reussi l'attaque avec le flipper !");
        reset_setup_flipper(app, prev_sec, prev_mili_sec);
        app->state = ST_INGAME;
        app->interaction->active = false;
    }
}

static int circle_create(int time_int, app_t *app,
int prev_mili_int, int time_mili_int)
{
    task_t *node = find_task_node(app, 3);

    if (NB_CIRCLE_CREATE(node) != NB_CIRCLE_FLIPPER(node)) {
        if (handler_create_circle(time_int, app,
        prev_mili_int, time_mili_int) == 84)
            return 84;
    }
    return 0;
}

static void game_second(int prev_sec, int time_int, app_t *app)
{
    if (prev_sec < time_int) {
        open_circle(app, time_int);
        life_loose(app, time_int);
    }
}

int app_task_flipper_core(app_t *app, renderer_t *renderer)
{
    task_t *node = find_task_node(app, 3);
    static int prev_sec = 0;
    static int prev_mili_sec = 0;
    int time_mili_int = 0;
    int time_int = (int) TIME_FLOAT(node->content.flipper);

    if (FLIPPER_STARTED(node) == true) {
        if (init_task_flipper(app) == 84)
            return 84;
    }
    time_handler(app, &time_mili_int);
    game_result(app, &prev_sec, &prev_mili_sec, renderer);
    if (circle_create(time_int, app, prev_mili_sec, time_mili_int) == 84)
        return 84;
    if (prev_mili_sec < time_mili_int)
        circle_expension(app);
    game_second(prev_sec, time_int, app);
    prev_sec = time_int;
    prev_mili_sec = time_mili_int;
    return 0;
}
