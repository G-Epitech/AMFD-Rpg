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

int network_connexion_host(renderer_t *renderer, app_t *app, button_t *button)
{
    sfTcpListener* listener = sfTcpListener_create();
    sfTcpSocket* client;

    (void) renderer;
    (void) button;
    if (sfTcpListener_listen(listener, 53000, sfIpAddress_Any) != sfSocketDone)
        return 1;
    if (sfTcpListener_accept(listener, &client) != sfSocketDone)
        return 1;
    app->network->listener = listener;
    app->network->socket = client;
    app->state = ST_CHOICE;
    app->partner = players_add(app->players, "Player2");
    return 0;
}
