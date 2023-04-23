/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** settings
*/

#include <stdlib.h>
#include "types/renderer/types.h"
#include "types/dialog_box/dialog_box.h"
#include "app/types.h"

bool app_init_dialog_box(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    app->dialog_box = dialog_box_new();
    if (!app->dialog_box)
        return false;
    app->dialog_box->show = false;
    app->dialog_box->mode = DGBOX_DIALOG;
    return true;
}
