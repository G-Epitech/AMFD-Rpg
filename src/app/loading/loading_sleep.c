/*
** EPITECH PROJECT, 2023
** loading_sleep.c
** File description:
** Loading sleep
*/

#include <stdio.h>
#include <unistd.h>
#include "my/include/my.h"
#include "app/loading/types.h"
#include "types/renderer/renderer.h"

void loading_sleep(int time)
{
    sfClock *clock = sfClock_create();

    while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) != time) {};
    sfClock_destroy(clock);
}
