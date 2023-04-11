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

static void dispatch_data(app_t *app, char *data)
{
    cjson_t *json = cjson_parse(data);
    char *event = NULL;

    if (!cjson_get_prop_string(json, "event", &event))
        return;
    if (!my_strcmp(event, "position"))
        network_receive_position(app, json);
}

void network_receive_game(app_t *app)
{
    sfTcpSocket *socket = app->network->socket;
    sfSocketStatus status = sfSocketNotReady;
    sfPacket *packet = sfPacket_create();
    char *data = NULL;

    sfTcpSocket_setBlocking(app->network->socket, sfFalse);
    status = sfTcpSocket_receivePacket(socket, packet);
    if (status == sfSocketDone) {
        data = malloc(sfPacket_getDataSize(packet));
        sfPacket_readString(packet, data);
        dispatch_data(app, data);
        free(data);
    }
    sfPacket_destroy(packet);
}
