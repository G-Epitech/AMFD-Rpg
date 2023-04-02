/*
** EPITECH PROJECT, 2023
** map.c
** File description:
** Display a map
*/

#include <SFML/Graphics.h>

void display_map(sfTexture *texture, sfRenderWindow *window, sfSprite *sprite)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
    sfSprite_setScale(sprite, (sfVector2f) {1, 1});
    sfRenderWindow_drawSprite(window, sprite, NULL);
}
