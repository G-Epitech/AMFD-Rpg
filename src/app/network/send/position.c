/*
** EPITECH PROJECT, 2023
** position.c
** File description:
** Send position to an other player
*/

#include <stdio.h>
#include <SFML/Network.h>
#include "app/types.h"
#include "app/network/network.h"
#include "cjson/include/cjson.h"

void network_send_position(app_t *app)
{
    sfVector2f position = app->player->position;
    int orientation = app->player->orientation;
    char *event = "position";
    cjson_t *data = cjson_new("Packet");

    cjson_set_prop(data, "event", CJSON(event), CJSON_STRING_T);
    cjson_set_prop(data, "x", CJSON_NUMBER(position.x), CJSON_NUMBER_T);
    cjson_set_prop(data, "y", CJSON_NUMBER(position.y), CJSON_NUMBER_T);
    cjson_set_prop(data, "orientation", CJSON_NUMBER(orientation),
    CJSON_NUMBER_T);
    network_send_string(app, cjson_stringify(data));
    cjson_free(data);
}
