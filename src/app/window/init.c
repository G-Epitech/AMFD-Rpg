/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** @Made by Math alias T1nt1n
** Init main window
*/

#include <SFML/Graphics.h>
#include "app/window/window.h"

sfRenderWindow *window_init(bool fullscreen)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = WIN_VIDEO_MODE;
    char *name = WIN_TITLE;
    int fps = WIN_FPS;
    sfUint32 style = sfResize | sfClose;

    if (fullscreen)
        style = sfResize | sfClose | sfFullscreen;
    window = sfRenderWindow_create(video_mode, name, style, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    return window;
}
