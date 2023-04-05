/*
** EPITECH PROJECT, 2023
** vector.c
** File description:
** Get vector by json
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/components/types.h"
#include "types/components/components.h"
#include "types/renderer/types.h"
#include "types/list/types.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"

sfVector2f cjson_vector(cjson_t *config)
{
    cjson_t *position_prop = NULL;
    sfVector2f position = {0, 0};

    position_prop = cjson_get_prop(config, "position");
    if (!position_prop)
        return position;
    position.x = cjson_get_prop_float_unsafe(position_prop, "x");
    position.y = cjson_get_prop_float_unsafe(position_prop, "y");
    return position;
}
