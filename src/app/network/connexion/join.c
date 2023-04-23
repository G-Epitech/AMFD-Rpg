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
#include "types/dialog_box/dialog_box.h"

static void network_connexion_join_start(app_t *app, char *input)
{
    sfIpAddress server;
    sfTcpSocket* socket = sfTcpSocket_create();

    if (!input)
        return;
    server = sfIpAddress_fromString(input);
    if (sfTcpSocket_connect(socket, server, 53000, sfTime_Zero) !=
    sfSocketDone) {
        app->state = ST_GAMEMODE;
        return;
    }
    app->network->socket = socket;
    app->state = ST_CHOICE;
    app->partner = players_add(app->players, "Player2");
}

int network_connexion_join(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    app->dialog_box->show = true;
    dialog_box_reset_events(app->dialog_box, true);
    dialog_box_set_message(app->dialog_box, "Saisissez l'IP du joueur");
    app->dialog_box->mode = DGBOX_INPUT;
    dialog_box_set_input(app->dialog_box, "127.0.0.1");
    dialog_box_set_option1(app->dialog_box, "Connexion");
    dialog_box_set_option2(app->dialog_box, "Annuler");
    dialog_box_set_option3(app->dialog_box, NULL);
    app->dialog_box->onoption1 = &network_connexion_join_start;
    return 0;
}
