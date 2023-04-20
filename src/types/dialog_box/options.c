/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** new
*/

#include <stdlib.h>
#include "my/include/my.h"
#include "types/dialog_box/types.h"

void dialog_box_set_option1(dialog_box_t *dialog_box, char *option)
{
    if (!dialog_box)
        return;
    free(dialog_box->option1);
    if (option)
        dialog_box->option1 = my_strdup(option);
    else
        dialog_box->option1 = NULL;
}

void dialog_box_set_option2(dialog_box_t *dialog_box, char *option)
{
    if (!dialog_box)
        return;
    free(dialog_box->option2);
    if (option)
        dialog_box->option2 = my_strdup(option);
    else
        dialog_box->option2 = NULL;
}

void dialog_box_set_option3(dialog_box_t *dialog_box, char *option)
{
    if (!dialog_box)
        return;
    free(dialog_box->option3);
    if (option)
        dialog_box->option3 = my_strdup(option);
    else
        dialog_box->option3 = NULL;
}
