/*
** EPITECH PROJECT, 2023
** app.h
** File description:
** App functions
*/

#ifndef APP_H_
    #define APP_H_

    #include "app/types.h"

typedef struct s_renderer renderer_t;
typedef struct s_button button_t;

/**
 * @brief Init application
 * @return The new app structure
*/
app_t *app_init(renderer_t *renderer);

/**
 * @brief Free given app
 * @param app App object to free
 */
void app_free(app_t *app);

/**
 * @brief Run application
 * @param renderer Main renderer function
 * @param app Application structure
 */
int app_run(renderer_t *renderer, app_t *app);

/**
 * @brief Check if a sepcific state is active
 * @param app Application structure
 * @param states List of states
 * @param size Size of the list
 * @return true The state is active
 * @return false The state is not active
 */
bool app_on_state(app_t *app, app_states_t *states, size_t size);

/**
 * @brief Initialize controller of app
 * @param app App object on which init controller
 * @param renderer Renderer object
 * @return Initilalization success status
 */
bool app_init_controller(app_t *app, renderer_t *renderer);

/**
 * @brief Initialize settings of app
 * @param app App object
 * @param renderer Renderer object
 * @return Initialization success status
 */
bool app_init_settings(app_t *app, renderer_t *renderer);

/**
 * @brief Initialize items of game
 * @param app App object
 * @param renderer Renderer object
 * @return Initialization success status
 */
bool app_init_items(app_t *app, renderer_t *renderer);

/**
 * @brief Initialize network of game
 * @param app App object
 * @param renderer Renderer object
 * @return Initialization success status
 */
bool app_init_network(app_t *app, renderer_t *renderer);

/**
 * @brief Initialize npcs of game
 * @param app App object
 * @param renderer Renderer object
 * @return Initialization success status
 */
bool app_init_npcs(app_t *app, renderer_t *renderer);

/**
 * @brief Initialize tasks of game
 * @param app App object
 * @param renderer Renderer object
 * @return Initialization success status
 */
bool app_init_tasks(app_t *app, renderer_t *renderer);

/**
 * @brief Initialize tasks of game
 * @param app App object
 * @param renderer Renderer object
 * @return Initialization success status
 */
bool app_init_interactions(app_t *app, renderer_t *renderer);

/**
 * @brief Initialize players of game
 * @param app App object
 * @param renderer Renderer object
 * @return Initialization success status
 */
bool app_init_players(app_t *app, renderer_t *renderer);

/**
 * @brief Down state
 * @param renderer Main renderer function
 * @param app Application structure
 */
int states_switch_left(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Up state
 * @param renderer Main renderer function
 * @param app Application structure
 */
int states_switch_right(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Select the charater in the choice menu
 * @param renderer Main renderer function
 * @param app Application structure
 */
int states_select_character(renderer_t *renderer, app_t *app,
button_t *button);

/**
 * @brief Reload json
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Button
 */
int developer_reload_json(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Handle click on usb key
 * @param renderer Main renderer function
 * @param app Application structure
 * @param button Button struct with all settings
*/
int brute_force_click(renderer_t *renderer, app_t *app, button_t *button);

#endif /* !APP_H_ */
