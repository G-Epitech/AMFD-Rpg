/*
** EPITECH PROJECT, 2023
** function.c
** File description:
** @Made by Math alias T1nt1n
** Function header for window
*/
#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <SFML/Graphics.h>
    #include "app/types.h"

    #define WIN_FPS 120
    #define WIN_VIDEO_MODE ((sfVideoMode) {1920, 1080, 32})
    #define LOWER_WIN_VIDEO_MODE ((sfVideoMode) {820, 600, 32})
    #define MEDIUM_WIN_VIDEO_MODE ((sfVideoMode) {1920, 1080, 32})
    #define HIGH_WIN_VIDEO_MODE ((sfVideoMode) {2560, 1600, 32})
    #define WIN_TITLE "Hackers Quests"
    #define ICON_FILE "assets/components/backgrounds/bras_gauche.png"

typedef struct s_renderer renderer_t;
typedef struct s_button button_t;

/**
 * Init a new window
 * @return The new window
 */
sfRenderWindow *window_init(bool fullscreen, sfVideoMode resolution);

/**
 * @brief Close the window
 * @param renderer Renderer structure
 * @param app App structure
 */
int window_close(renderer_t *renderer, app_t *app, button_t *button);
#endif //WINDOW_H_
