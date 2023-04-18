/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** Core animation functions
*/

#include "app/app.h"
#include "app/animation/animation.h"

void core_handle_animation(app_t *app, renderer_t *renderer)
{
    animate_player(app, renderer);
}
