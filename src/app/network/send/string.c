/*
** EPITECH PROJECT, 2023
** json.c
** File description:
** Send json data
*/

#include <stdio.h>
#include <SFML/Network.h>
#include "app/types.h"
#include "app/network/network.h"
#include "cjson/include/cjson.h"

void network_send_string(app_t *app, char *data)
{
    sfPacket *packet = sfPacket_create();

    sfPacket_writeString(packet, data);
    sfTcpSocket_sendPacket(app->network->socket, packet);
    sfPacket_destroy(packet);
    free(data);
}
