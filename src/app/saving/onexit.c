/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** onexit
*/

#include <stdbool.h>
#include "app/types.h"
#include "types/dialog_box/dialog_box.h"
#include "app/saving/saving.h"

static void on_non_save(app_t *app, char *input)
{
    saver_t *saver = (saver_t *) app->dialog_box->context;

    (void) input;
    sfRenderWindow_close(saver->window);
}

static void on_save(app_t *app, char *input)
{
    saver_t *saver = (saver_t *) app->dialog_box->context;

    (void) input;
    save_ask_file(app, saver);
}

static void set_up_dialog(dialog_box_t *dialog_box, saver_t *saver)
{
    dialog_box->context = saver;
    dialog_box->mode = DGBOX_DIALOG;
    dialog_box->show = true;
    dialog_box_reset_events(dialog_box, true);
    dialog_box->afteroption1 = &on_save;
    dialog_box->onoption2 = &on_non_save;
    dialog_box_set_message(
        dialog_box,
        "Voulez-vous enregistrer votre partie\nen cours ?"
    );
    dialog_box_set_option1(dialog_box, "Oui");
    dialog_box_set_option2(dialog_box, "Non");
    dialog_box_set_option3(dialog_box, NULL);
}

bool save_ask_on_exit(app_t *app, sfRenderWindow *window)
{
    saver_t *saver = NULL;

    if (app->state < ST_INGAME)
        return false;
    saver = saver_new();
    if (!saver)
        return false;
    saver->window = window;
    saver->close_window = true;
    set_up_dialog(app->dialog_box, saver);
    return true;
}
