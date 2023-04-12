/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** network
*/

#include <stdlib.h>
#include "app/types.h"
#include "app/network/network.h"

bool app_init_network(app_t *app)
{
    app->network = network_init();
    return app->network ? true : false;
}
