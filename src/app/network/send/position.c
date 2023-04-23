/*
** EPITECH PROJECT, 2023
** position.c
** File description:
** Send position to an other player
*/

#include <stdio.h>
#include <SFML/Network.h>
#include <time.h>
#include "my/include/my.h"
#include "app/types.h"
#include "app/network/network.h"
#include "cjson/include/cjson.h"
#include "my/include/my.h"

static bool improve_position(app_t *app)
{
    sfVector2f position = app->player->position;
    sfVector2f last_position = app->network->position;

    if (last_position.x - position.x > - 2 && last_position.x - position.x < 2 &&
    last_position.y - position.y > - 2 && last_position.y - position.y < 2)
        return false;
    return true;
}

void network_send_position(app_t *app)
{
    sfVector2f position = app->player->position;
    sfIntRect rect = app->player->rect;
    char *event = "position";
    cjson_t *data = cjson_new("Packet");

    if (!improve_position(app))
        return;
    cjson_set_prop(data, "event", CJSON(event), CJSON_STRING_T);
    cjson_set_prop(data, "x", CJSON_NUMBER(position.x), CJSON_NUMBER_T);
    cjson_set_prop(data, "y", CJSON_NUMBER(position.y), CJSON_NUMBER_T);
    cjson_set_prop(data, "height", CJSON_NUMBER(rect.height), CJSON_NUMBER_T);
    cjson_set_prop(data, "width", CJSON_NUMBER(rect.width), CJSON_NUMBER_T);
    cjson_set_prop(data, "left", CJSON_NUMBER(rect.left), CJSON_NUMBER_T);
    cjson_set_prop(data, "top", CJSON_NUMBER(rect.top), CJSON_NUMBER_T);
    network_send_string(app, cjson_stringify(data, NULL));
    app->network->position = position;
    cjson_free(data);
}
