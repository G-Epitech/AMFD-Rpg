/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** new
*/

#include <stdlib.h>
#include "my/include/my.h"
#include "types/dialog_box/dialog_box.h"

static void dialog_box_onoption1(dialog_box_t *dialog_box, app_t *app)
{
    char *input = NULL;

    if (!dialog_box)
        return;
    if (!dialog_box->onoption1)
        return;
    if (dialog_box->mode == DGBOX_DIALOG)
        dialog_box->onoption1(app, NULL);
    if (dialog_box->mode == DGBOX_INPUT) {
        input = dialog_box_get_input(dialog_box);
        dialog_box->onoption1(app, input);
    }
}

static void dialog_box_onoption2(dialog_box_t *dialog_box, app_t *app)
{
    char *input = NULL;

    if (!dialog_box)
        return;
    if (!dialog_box->onoption2)
        return;
    if (dialog_box->mode == DGBOX_DIALOG)
        dialog_box->onoption2(app, NULL);
    if (dialog_box->mode == DGBOX_INPUT) {
        input = dialog_box_get_input(dialog_box);
        dialog_box->onoption2(app, input);
    }
}

static void dialog_box_onoption3(dialog_box_t *dialog_box, app_t *app)
{
    char *input = NULL;

    if (!dialog_box)
        return;
    if (!dialog_box->onoption3)
        return;
    if (dialog_box->mode == DGBOX_DIALOG)
        dialog_box->onoption3(app, NULL);
    if (dialog_box->mode == DGBOX_INPUT) {
        input = dialog_box_get_input(dialog_box);
        dialog_box->onoption3(app, input);
    }
}

void dialog_box_onvalid(dialog_box_t *dialog_box, app_t *app)
{
    dialog_box->show = false;
    if (dialog_box->option == 1)
        return dialog_box_onoption1(dialog_box, app);
    if (dialog_box->option == 2)
        return dialog_box_onoption2(dialog_box, app);
    if (dialog_box->option == 3)
        return dialog_box_onoption3(dialog_box, app);
}
