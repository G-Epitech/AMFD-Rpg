/*
** EPITECH PROJECT, 2022
** close_window.c
** File description:
** Close windows
*/

#include "SFML/Graphics.h"

void event_window_close(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
