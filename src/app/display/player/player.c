/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player
*/

#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

void display_player(renderer_t *renderer, player_t *player)
{
    sfVector2f position = player->position;
    int skin_id = player->skin_id;
    skin_orientation_t orientation = player->orientation;

    display_character(renderer, position, skin_id, orientation);
}
