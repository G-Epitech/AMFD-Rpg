/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init components ressoruces
*/

#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/players/types.h"

components_r_t *ressources_components_init(void)
{
    components_r_t *components = malloc(sizeof(components_r_t));

    if (!components)
        return NULL;
    components->button = NULL;
    components->lever = NULL;
    components->backgrounds = NULL;
    return components;
}
