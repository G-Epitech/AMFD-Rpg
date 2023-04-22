/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** new
*/

#include <stdlib.h>
#include "types/dialog_box/types.h"

dialog_box_t *dialog_box_new(void)
{
    dialog_box_t *dialog = malloc(sizeof(dialog_box_t));

    if (!dialog)
        return NULL;
    *dialog = (dialog_box_t) {
        DGBOX_DIALOG,
        NULL, NULL, NULL, NULL, NULL,
        1, false, NULL,
        NULL, NULL, NULL, NULL, NULL, NULL
    };
    return dialog;
}
