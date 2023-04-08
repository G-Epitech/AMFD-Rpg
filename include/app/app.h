/*
** EPITECH PROJECT, 2023
** app.h
** File description:
** App functions
*/

#ifndef APP_H_
    #define APP_H_

    #include "app/types.h"
    #include "app/utils/utils.h"

typedef struct s_renderer renderer_t;
typedef struct s_button button_t;

/**
 * @brief Init application
 * @return The new app structure
*/
app_t *app_init(void);

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

#endif /* !APP_H_ */
