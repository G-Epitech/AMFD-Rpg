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
    app->dialog_box->show = true;
    dialog_box_set_message(app->dialog_box,
    "Voulez-vous vendre cet item pour\n2 pieces ?");
    dialog_box_set_option1(app->dialog_box, "Consommer");
    dialog_box_set_option2(app->dialog_box, "Vendre");
    return true;
}
