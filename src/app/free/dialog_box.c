/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory_move
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/renderer/types.h"
#include "types/dialog_box/dialog_box.h"

void app_free_dialog_box(app_t *app)
{
    if (!app->dialog_box)
        return;
    dialog_box_free(app->dialog_box);
}
