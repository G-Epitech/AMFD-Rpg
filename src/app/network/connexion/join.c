/*
** EPITECH PROJECT, 2023
** host.c
** File description:
** Host connexion
*/

#include <stdio.h>
#include <SFML/Network.h>
#include "types/renderer/types.h"
#include "app/types.h"
#include "types/players/players.h"

int network_connexion_join(renderer_t *renderer, app_t *app, button_t *button)
{
    sfIpAddress server = sfIpAddress_LocalHost;
    sfTcpSocket* socket = sfTcpSocket_create();

    (void) renderer;
    (void) button;
    if (sfTcpSocket_connect(socket, server, 53000, sfTime_Zero) !=
    sfSocketDone) {
        app->state = ST_GAMEMODE;
        return 1;
    }
    app->network->socket = socket;
    app->state = ST_CHOICE;
    app->partner = players_add(app->players, "Player2");
    return 0;
}
