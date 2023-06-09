/*
** EPITECH PROJECT, 2023
** components.h
** File description:
** Components functions
*/

#ifndef COMPONENTS_H_
    #define COMPONENTS_H_

    #include <SFML/Graphics.h>
    #include "types.h"
    #include "types/list/types.h"
    #include "cjson/include/cjson.h"

/**
 * @brief Load all components
*/
components_t *components_load(renderer_t *renderer);

/**
 * @brief Append a new button in a list
 * @param list List of buttons
 * @param position Position of the button
 * @param app_state State of the app when the button must be display
 * @return The new button data
*/
button_t *buttons_append(list_t *list, sfVector2f position,
app_states_t *app_state);

/**
 * @brief Load all buttons with json configuration
 * @param renderer Renderer structure
 * @param components Components list
 * @param buttons json array of all buttons
*/
void buttons_load(renderer_t *renderer, components_t *components,
cjson_array_t *buttons);

/**
 * @brief Append a new lever in a list
 * @param list List of levers
 * @param position Position of the lever
 * @param app_state State of the app when the lever must be display
 * @return The new lever data
*/
lever_t *levers_append(list_t *list, sfVector2f position,
app_states_t app_state);

/**
 * @brief Load all levers with json configuration
 * @param components Components list
 * @param levers json array of all buttons
*/
void levers_load(components_t *components, cjson_array_t *levers);

/**
 * @brief Load all progress bar of app
 * @param components Components list
 * @param progresses CJSON array of all progress bars
 */
void progresses_load(components_t *components, cjson_array_t *progresses);

/**
 * @brief Get cjson vector
 * @param config Json configuration
 * @param prop Key of property to get
 * @return New vector
*/
sfVector2f cjson_vector(cjson_t *config, char *prop);

#endif /* !COMPONENTS_H_ */
