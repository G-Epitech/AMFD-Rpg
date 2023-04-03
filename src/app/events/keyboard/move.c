/*
** EPITECH PROJECT, 2023
** move.c
** File description:
** Move keys
*/

#include <SFML/Graphics.h>
#include "app/app.h"
#include "types/players/types.h"
#include "app/events/types.h"

void keyboard_press_move(sfEvent event, app_t *app)
{
    if (event.key.code == sfKeyZ)
        app->control->up = true;
    if (event.key.code == sfKeyS)
        app->control->down = true;
    if (event.key.code == sfKeyQ)
        app->control->left = true;
    if (event.key.code == sfKeyD)
        app->control->right = true;
}

void keyboard_release_move(sfEvent event, app_t *app)
{
    if (event.key.code == sfKeyZ)
        app->control->up = false;
    if (event.key.code == sfKeyS)
        app->control->down = false;
    if (event.key.code == sfKeyQ)
        app->control->left = false;
    if (event.key.code == sfKeyD)
        app->control->right = false;
}
