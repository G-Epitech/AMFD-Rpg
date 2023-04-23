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

void network_send_quests(app_t *app)
{
    char *event = "quests";
    cjson_t *data = cjson_new("Packet");

    cjson_set_prop(data, "event", CJSON(event), CJSON_STRING_T);
    network_send_string(app, cjson_stringify(data, NULL));
    cjson_free(data);
}
