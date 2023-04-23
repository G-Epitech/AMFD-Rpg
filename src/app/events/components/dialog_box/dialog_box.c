/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** onvalid
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/types.h"
#include "app/events/events.h"
#include "types/dialog_box/dialog_box.h"

void event_dialog_box_onkeypress(app_t *app, sfEvent event)
{
    if (event.key.code == sfKeyUp || event.key.code == sfKeyDown)
        return event_dialog_box_set_option(app->dialog_box, event.key.code);
    if (event.key.code == sfKeyEnter)
        return dialog_box_onvalid(app->dialog_box, app);
}
