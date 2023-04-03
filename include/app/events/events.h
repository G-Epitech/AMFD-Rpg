/*
** EPITECH PROJECT, 2023
** events.h
** File description:
** Events functions
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include <SFML/Graphics.h>
    #include "app/types.h"

/**
 * @brief Handle all events
 * @param window Window of the app
 * @param event The specific event
*/
void event_handle(sfRenderWindow *window, sfEvent event, app_t *app);

/**
 * @brief Close window
 * @param window Window of the app
*/
void event_window_close(sfRenderWindow *window);

/**
 * @brief Detects when a movement key is pressed
 * @param event The event
 * @param app Application structure
*/
void keyboard_press_move(sfEvent event, app_t *app);

/**
 * @brief Detects when a movement key is released
 * @param event The event
 * @param app Application structure
*/
void keyboard_release_move(sfEvent event, app_t *app);

#endif /* !EVENTS_H_ */
