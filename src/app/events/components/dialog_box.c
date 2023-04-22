/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** onvalid
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/types.h"
#include "types/dialog_box/dialog_box.h"

static int get_nb_options(dialog_box_t *dialog_box)
{
    int nb = 0;

    if (dialog_box->option1)
        nb += 1;
    if (dialog_box->option2)
        nb += 1;
    if (dialog_box->option3)
        nb += 1;
    return nb;
}

static void set_option(dialog_box_t *dialog_box, sfKeyCode code)
{
    int nb = get_nb_options(dialog_box);
    int option = dialog_box->option;

    option += code == sfKeyUp ? -1 : 1;
    if (option > nb)
        option = 1;
    if (option <= 0)
        option = nb;
    dialog_box->option = option;
}

void events_dialog_box_onkeypress(app_t *app, sfEvent event)
{
    if (event.key.code == sfKeyUp || event.key.code == sfKeyDown)
        return set_option(app->dialog_box, event.key.code);
    if (event.key.code == sfKeyEnter)
        return dialog_box_onvalid(app->dialog_box, app);
}
