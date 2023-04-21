/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** new
*/

#include <stdlib.h>
#include "my/include/my.h"
#include "types/dialog_box/types.h"

void dialog_box_set_message(dialog_box_t *dialog_box, char *message)
{
    if (!dialog_box)
        return;
    free(dialog_box->message);
    dialog_box->message = my_strdup(message);
}
