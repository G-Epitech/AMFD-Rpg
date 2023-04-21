/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** new
*/

#include <stdlib.h>
#include "types/dialog_box/types.h"

void dialog_box_free(dialog_box_t *dialog_box)
{
    if (!dialog_box)
        return;
    free(dialog_box->message);
    free(dialog_box->option1);
    free(dialog_box->option2);
    free(dialog_box->option3);
    free(dialog_box);
}
