/*
** EPITECH PROJECT, 2023
** shake_attack.c
** File description:
** Shake attack button
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "app/animations/types.h"
#include "app/types.h"
#include "types/list/list.h"

animation_event_shake_attack_t *animations_shake_attack_init(void)
{
    animation_event_shake_attack_t *shake = malloc(sizeof
    (animation_event_shake_attack_t));

    if (!shake)
        return NULL;
    shake->last_time = 0;
    shake->total_time = 0;
    shake->attack = NULL;
    shake->origin = (sfVector2f) {0, 0};
    shake->target_time = SHAKE_TARGET;
    shake->target_offset = -10;
    shake->total_offset = -5;
    return shake;
}

void animations_shake_attack_add(list_t *events, attack_t *attack)
{
    node_data_t data;
    node_t *node = NULL;

    data.animations_event = malloc(sizeof(animation_event_t));
    if (!data.animations_event)
        return;
    data.animations_event->type = AE_SHAKE_ATTACK;
    data.animations_event->data.shake_attack = animations_shake_attack_init();
    if (!data.animations_event->data.shake_attack) {
        free(data.animations_event);
        return;
    }
    data.animations_event->data.shake_attack->attack = attack;
    data.animations_event->data.shake_attack->origin = attack->position;
    node = node_new(data);
    if (!node)
        return;
    list_append(events, node);
}

static void shake_attack(animation_event_shake_attack_t *shake)
{
    if (shake->target_offset < 0) {
        shake->attack->position.x--;
        shake->total_offset--;
    } else {
        shake->attack->position.x++;
        shake->total_offset++;
    }
    if (shake->total_offset == shake->target_offset) {
        shake->total_offset = 0;
        if (shake->target_offset < 0)
            shake->target_offset = 10;
        else
            shake->target_offset = -10;
    }
}

bool animations_shake_attack(animation_event_shake_attack_t *shake,
sfClock *clock)
{
    sfTime elapsed_time;
    sfInt32 time = 0;

    if (!shake || !shake->attack || !clock)
        return true;
    elapsed_time = sfClock_getElapsedTime(clock);
    time = sfTime_asMilliseconds(elapsed_time);
    shake->attack->shake = true;
    if (time >= shake->last_time + SHAKE_TIME) {
        shake->last_time = time;
        shake_attack(shake);
        shake->total_time += SHAKE_TIME;
    }
    if (shake->total_time >= shake->target_time) {
        shake->attack->shake = false;
        shake->attack->position = shake->origin;
        free(shake);
        return true;
    }
    return false;
}
