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
#include "types/components/components.h"
#include "types/dialog_box/dialog_box.h"

static void on_load(app_t *app, char *input)
{
    (void) app;
    printf("Load from [%s]\n", input);
}

static void set_up_dialog(dialog_box_t *dialog_box)
{
    dialog_box->context = NULL;
    dialog_box->mode = DGBOX_INPUT;
    dialog_box->show = true;
    dialog_box_reset_events(dialog_box, true);
    dialog_box_set_message(
        dialog_box,
        "Saisissez le chemin vers le fichier de partie\n"
        "que vous voulez charger :"
    );
    dialog_box_set_input(dialog_box, "");
    dialog_box_set_option1(dialog_box, "Ouvrir");
    dialog_box_set_option2(dialog_box, "Annuler");
    dialog_box_set_option3(dialog_box, NULL);
    dialog_box->option = 1;
    dialog_box->onoption1 = &on_load;
}

int save_load_ask_file(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    set_up_dialog(app->dialog_box);
    return 0;
}
