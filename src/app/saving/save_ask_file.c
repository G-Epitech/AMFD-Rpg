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
#include "types/dialog_box/dialog_box.h"

static void check_close_window(saver_t *saver)
{
    if (!saver)
        return;
    if (saver->close_window)
        sfRenderWindow_close(saver->window);
}

static void on_save(app_t *app, char *input)
{
    saver_t *saver = (saver_t *) app->dialog_box->context;

    app->dialog_box->afteroption1 = NULL;
    printf("Saved into [%s]\n", input);
    check_close_window(saver);
    saver_free(saver);
}

static void set_up_dialog(dialog_box_t *dialog_box, saver_t *saver)
{
    dialog_box->context = NULL;
    dialog_box->mode = DGBOX_INPUT;
    dialog_box->show = true;
    dialog_box_reset_events(dialog_box, false);
    dialog_box_set_message(
        dialog_box,
        "Saisissez le nom du fichier dans\nlequel enregistrer la partie :"
    );
    dialog_box_set_input(dialog_box, "ma_partie.hksqt");
    dialog_box_set_option1(dialog_box, "Valider");
    dialog_box_set_option2(dialog_box, "Annuler");
    dialog_box_set_option3(dialog_box, NULL);
    dialog_box->option = 1;
    dialog_box->onoption1 = &on_save;
    dialog_box->context = saver;
}

void save_ask_file(app_t *app, saver_t *saver)
{
    set_up_dialog(app->dialog_box, saver);
}
