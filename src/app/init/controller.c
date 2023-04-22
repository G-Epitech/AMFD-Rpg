/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** controller
*/

#include <stdlib.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "app/types.h"

static void app_init_cursor(cursor_t *cursor)
{
    cursor->texture = sfTexture_createFromFile(CURSOR_FILE, NULL);
    if (!cursor->texture)
        return;
    cursor->pos = (sfVector2f) {0.0, 0.0};
}

bool app_init_controller(app_t *app, renderer_t *renderer)
{
    control_t *control = malloc(sizeof(control_t) * 4);
    sfKeyCode key_codes[4] = {sfKeyD, sfKeyZ, sfKeyQ, sfKeyS};
    sfVector2f move_offset[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    control->cursor = malloc(sizeof(cursor_t));

    (void) renderer;
    if (!control || !control->cursor)
        return false;
    for (size_t i = 0; i < 4; i++) {
        control[i].direction = false;
        control[i].key = key_codes[i];
        control[i].offset = move_offset[i];
    }
    control->direction_nb = 0;
    app_init_cursor(control->cursor);
    app->control = control;
    return true;
}
