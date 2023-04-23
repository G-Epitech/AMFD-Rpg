/*
** EPITECH PROJECT, 2023
** receive.c
** File description:
** Receive packets
*/

#include <stdio.h>
#include <SFML/Network.h>
#include "app/types.h"
#include "app/network/network.h"

void network_receive(app_t *app, renderer_t *renderer)
{
    if (!app->network->socket)
        return;
    if (app->state == ST_CHOICE)
        network_receive_character(app);
    if (app->state == ST_INGAME && app->partner)
        network_receive_game(app, renderer);
}
