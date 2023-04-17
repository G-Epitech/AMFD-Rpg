/*
** EPITECH PROJECT, 2023
** animations.c
** File description:
** Display animations
*/

#include "types/renderer/types.h"
#include "app/types.h"
#include "app/display/display.h"

void display_animations(renderer_t *renderer, app_t *app)
{
    display_animations_floating_text(renderer, app);
    display_animations_notif(renderer, app);
}
