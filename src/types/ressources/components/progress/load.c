/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "types/ressources/types.h"
#include "cjson/include/cjson.h"

sfTexture *ressources_components_progress_load(cjson_t *config)
{
    char *texture_path = cjson_get_prop_string_unsafe(config, "progress");
    sfTexture *texture = NULL;

    if (texture_path)
        texture = sfTexture_createFromFile(texture_path, NULL);
    if (!texture)
        texture = sfTexture_create(1920, 1080);
    free(texture_path);
    return texture;
}
