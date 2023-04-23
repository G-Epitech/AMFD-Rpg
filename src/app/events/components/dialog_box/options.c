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

void event_dialog_box_set_option(dialog_box_t *dialog_box, sfKeyCode code)
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
