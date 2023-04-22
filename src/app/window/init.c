/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** @Made by Math alias T1nt1n
** Init main window
*/

#include "my/include/my.h"
#include <SFML/Graphics.h>
#include "app/window/window.h"

static void window_set_icon(sfRenderWindow *window)
{
    sfImage *icon = sfImage_createFromFile(ICON_FILE);
    const sfUint8 *icon_pixel = NULL;
    sfVector2u icon_size = (sfVector2u) {0, 0};

    if (!icon) {
        return;
    }
    icon_pixel = sfImage_getPixelsPtr(icon);
    icon_size = sfImage_getSize(icon);
    sfRenderWindow_setIcon(window, icon_size.x, icon_size.y, icon_pixel);
}

sfRenderWindow *window_init(bool fullscreen, sfVideoMode resolution)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = resolution;
    char *name = WIN_TITLE;
    int fps = WIN_FPS;
    sfUint32 style = sfResize | sfClose;

    if (fullscreen)
        style = sfResize | sfClose | sfFullscreen;
    window = sfRenderWindow_create(video_mode, name, style, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    window_set_icon(window);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return window;
}
