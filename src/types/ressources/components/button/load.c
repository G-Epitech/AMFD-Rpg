/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load button ressources
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"

static void load_textures(button_r_t *button, char *left, char *right,
char *middle)
{
    button->left = sfTexture_createFromFile(left, NULL);
    button->right = sfTexture_createFromFile(right, NULL);
    button->middle = sfTexture_createFromFile(middle, NULL);
}

button_r_t *ressources_components_button_load(cjson_t *button_config)
{
    button_r_t *button = malloc(sizeof(button_r_t));
    char *left = NULL;
    char *right = NULL;
    char *middle = NULL;

    if (!button)
        return NULL;
    cjson_get_prop_string(button_config, "left", &left);
    cjson_get_prop_string(button_config, "right", &right);
    cjson_get_prop_string(button_config, "middle", &middle);
    if (!left || !middle || !right) {
        free(left);
        free(right);
        free(middle);
        free(button);
        return NULL;
    }
    load_textures(button, left, right, middle);
    return button;
}
