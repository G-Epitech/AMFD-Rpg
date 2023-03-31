/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** @Made by Math alias T1nt1n
** Init main window
*/

#include <SFML/Graphics.h>

sfRenderWindow *window_init(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    char *name = "RPG";
    int fps = 120;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    return window;
}
