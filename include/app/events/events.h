/*
** EPITECH PROJECT, 2023
** events.h
** File description:
** Events functions
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include <SFML/Graphics.h>

/**
 * @brief Handle all events
 * @param window Window of the app
 * @param event The specific event
*/
void event_handle(sfRenderWindow *window, sfEvent event);

/**
 * @brief Close window
 * @param window Window of the app
*/
void event_window_close(sfRenderWindow *window);

#endif /* !EVENTS_H_ */
