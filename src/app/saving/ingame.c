/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** onexit
*/

#include <stdio.h>
#include <stdbool.h>
#include "app/types.h"
#include "app/saving/saving.h"
#include "types/renderer/renderer.h"
#include "types/dialog_box/dialog_box.h"

int save_in_game(renderer_t *renderer, app_t *app, button_t *button)
{
    saver_t *saver = saver_new();

    (void) button;
    if (!saver)
        return -1;
    saver->close_window = false;
    saver->window = renderer->window;
    saver->renderer = renderer;
    save_ask_file(app, saver);
    return 0;
}
