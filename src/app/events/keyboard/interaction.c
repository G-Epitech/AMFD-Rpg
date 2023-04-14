/*
** EPITECH PROJECT, 2023
** interaction.c
** File description:
** Keyboard interaction
*/

#include <SFML/Graphics.h>
#include "app/app.h"
#include "types/players/types.h"
#include "app/events/types.h"

void keyboard_interaction(sfEvent event, app_t *app)
{
    if (event.key.code == sfKeyE && app->interaction->interaction) {
        //Code
    }
}
