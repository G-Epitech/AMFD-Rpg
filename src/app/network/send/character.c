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
#include "types/characters/types.h"

void network_send_character(app_t *app, skin_textures_t skin)
{
    sfTcpSocket *socket = app->network->socket;
    sfPacket *packet = sfPacket_create();

    sfPacket_writeInt32(packet, (sfInt32) skin);
    sfTcpSocket_sendPacket(socket, packet);
    if (app->partner->skin_id != -1) {
        app->state = ST_INGAME;
    }
}
