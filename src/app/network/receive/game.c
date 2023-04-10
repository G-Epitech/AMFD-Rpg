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

static void dispatch_data(app_t *app, char *data)
{

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
