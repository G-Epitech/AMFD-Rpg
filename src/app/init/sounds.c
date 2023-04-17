/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** sound
*/

#include <stdlib.h>
#include "app/types.h"
#include "app/sound/sound.h"

bool app_init_sounds(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    app->sound_board = load_sound_board();
    return true;
}
