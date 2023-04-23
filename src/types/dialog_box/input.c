/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** new
*/

#include <stdio.h>
#include <stdlib.h>
#include "my/include/my.h"
#include "types/dialog_box/dialog_box.h"

void dialog_box_add_input_char(dialog_box_t *dialog_box, char c)
{
    int len = 0;
    char *tmp = NULL;

    if (!dialog_box)
        return;
    len = my_strlen(dialog_box->input) + 1;
    tmp = malloc(len + 1);
    if (!tmp)
        return;
    tmp[0] = '\0';
    if (dialog_box->input)
        my_strcpy(tmp, dialog_box->input);
    tmp[len - 1] = c;
    tmp[len] = '\0';
    free(dialog_box->input);
    dialog_box->input = tmp;
}

void dialog_box_remove_input_char(dialog_box_t *dialog_box)
{
    int len = 0;

    if (!dialog_box)
        return;
    len = my_strlen(dialog_box->input);
    if (len - 1 < 0) {
        dialog_box->input[0] = '\0';
        return;
    }
    dialog_box->input[len - 1] = '\0';
}

void dialog_box_set_input(dialog_box_t *dialog_box, char *input)
{
    if (!dialog_box)
        return;
    free(dialog_box->input);
    dialog_box->input = my_strdup(input);
}

char *dialog_box_get_input(dialog_box_t *dialog_box)
{
    if (!dialog_box)
        return NULL;
    if (!dialog_box->input)
        return NULL;
    return my_strdup(dialog_box->input);
}
