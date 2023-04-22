/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** interactions
*/

#include "app/app.h"

bool core_interaction_detect_color(sfColor pixel, sfColor interaction_color)
{
    if (pixel.r != interaction_color.r || pixel.g != interaction_color.g ||
    pixel.b != interaction_color.b)
        return false;
    return true;
}
