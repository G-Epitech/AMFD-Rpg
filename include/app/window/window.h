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

    #define WIN_FPS 120
    #define WIN_VIDEO_MODE ((sfVideoMode) {1920, 1080, 32})

/**
 * Init a new window
 * @return The new window
 */
sfRenderWindow *window_init(void);
#endif //WINDOW_H_
