/*
** EPITECH PROJECT, 2023
** character.c
** File description:
** Send the selection of the character
*/

#include <stdio.h>
#include <SFML/Network.h>
#include "types/renderer/types.h"
#include "app/types.h"
#include "types/character/types.h"

void network_receive_character(app_t *app)
{
    sfTcpSocket *socket = app->network->socket;
    sfSocketStatus status = sfSocketNotReady;
    sfPacket *packet = sfPacket_create();

    sfTcpSocket_setBlocking(app->network->socket, sfFalse);
    status = sfTcpSocket_receivePacket(socket, packet);
    if (status == sfSocketDone) {
        app->partner->skin_id = (int) sfPacket_readUint32(packet);
        if (app->player->skin_id != -1)
            app->state = ST_INGAME;
    }
}
