/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** options
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/types.h"
#include "types/dialog_box/dialog_box.h"

static bool prevent_bad_input(sfUint32 code)
{
    sfUint32 bad[3] = {'\r', '\n', '\t'};

    if (code <= 0 || code >= 128)
        return true;
    for (size_t i = 0; i < 3; i++) {
        if (code == bad[i])
            return true;
    }
    return false;
}

void event_dialog_box_ontextentered(app_t *app, sfEvent event)
{
    sfUint32 code = event.text.unicode;

    if (prevent_bad_input(code))
        return;
    if (code == '\b')
        dialog_box_remove_input_char(app->dialog_box);
    else
        dialog_box_add_input_char(app->dialog_box, (char) code);
}
