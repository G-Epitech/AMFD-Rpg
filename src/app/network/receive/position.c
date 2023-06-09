/*
** EPITECH PROJECT, 2023
** receive.c
** File description:
** Receive packets
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Network.h>
#include "app/types.h"
#include "app/network/network.h"
#include "cjson/include/cjson.h"
#include "my/include/my.h"

static void get_rect(app_t *app, cjson_t *data)
{
    sfIntRect rect = {0, 0, 0, 0};

    if (!cjson_get_prop_int(data, "height", &rect.height))
        return;
    if (!cjson_get_prop_int(data, "width", &rect.width))
        return;
    if (!cjson_get_prop_int(data, "left", &rect.left))
        return;
    if (!cjson_get_prop_int(data, "top", &rect.top))
        return;
    app->partner->rect = rect;
}

void network_receive_position(app_t *app, cjson_t *data)
{
    float x = 0;
    float y = 0;
    int state = 0;

    if (!cjson_get_prop_float(data, "x", &x))
        return;
    if (!cjson_get_prop_float(data, "y", &y))
        return;
    if (!cjson_get_prop_int(data, "state", &state))
        return;
    get_rect(app, data);
    app->partner->position.x = x;
    app->partner->position.y = y;
    app->network->state = state;
}
