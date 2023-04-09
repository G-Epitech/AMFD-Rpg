/*
** EPITECH PROJECT, 2023
** receive.c
** File description:
** Receive packets
*/

#include <SFML/Network.h>
#include "app/types.h"
#include "app/network/network.h"

void network_receive(app_t *app)
{
    if (app->state == ST_CHOICE)
        network_receive_character(app);
}
