/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** @Made by Math alias T1nt1n
** Init main window
*/

#include <SFML/Graphics.h>
#include "app/window/window.h"

sfRenderWindow *window_init(void)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = WIN_VIDEO_MODE;
    char *name = WIN_TITLE;
    int fps = WIN_FPS;

    window = sfRenderWindow_create(video_mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    return window;
}
