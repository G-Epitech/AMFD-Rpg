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

void network_receive_position(app_t *app, cjson_t *data)
{
    float x = 0;
    float y = 0;
    int orientation = 0;

    if (!cjson_get_prop_float(data, "x", &x))
        return;
    if (!cjson_get_prop_float(data, "y", &y))
        return;
    if (!cjson_get_prop_int(data, "orientation", &orientation))
        return;
    app->partner->position.x = x;
    app->partner->position.y = y;
    app->partner->orientation = orientation;
}
