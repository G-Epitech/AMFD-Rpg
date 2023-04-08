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
    #include "types/renderer/types.h"

/**
 * @brief Handle all events
 * @param window Window of the app
 * @param event The specific event
*/
void event_handler(sfRenderWindow *window, app_t *app, renderer_t *renderer);

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

/**
 * @brief Handle events on buttons
 * @param renderer Renderer structure
 * @param app Application structure
 * @param event Event click
*/
void event_components_buttons(renderer_t *renderer, app_t *app, sfEvent event);

/**
 * @brief Handle events on levers
 * @param renderer Renderer structure
 * @param app Application structure
 * @param event Event click
*/
void event_components_levers(renderer_t *renderer, app_t *app, sfEvent event);

#endif /* !EVENTS_H_ */
