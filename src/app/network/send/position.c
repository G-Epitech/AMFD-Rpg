/*
** EPITECH PROJECT, 2023
** position.c
** File description:
** Send position to an other player
*/

#include <SFML/Network.h>
#include "app/types.h"
#include "app/network/network.h"
#include "cjson/include/cjson.h"

void network_send_position(app_t *app)
{
    sfVector2f position = app->player->position;
    int orientation = (int) app->player->orientation;
    char *event = "position";
    cjson_t *data = cjson_new("Packet");

    data->type = CJSON_OBJECT_T;
    cjson_set_prop(data, "event", CJSON(event), CJSON_STRING_T);
    cjson_set_prop(data, "x", CJSON(position.x), CJSON_NUMBER_T);
    cjson_set_prop(data, "y", CJSON(position.y), CJSON_NUMBER_T);
    cjson_set_prop(data, "orientation", CJSON(orientation), CJSON_NUMBER_T);
    //network_send_string(app, cjson_stringify(data));
    network_send_string(app, "test de fou");
}
