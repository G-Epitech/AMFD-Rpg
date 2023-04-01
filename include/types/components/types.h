/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Components types
*/

#ifndef COMPONENTS_TYPES_H_
    #define COMPONENTS_TYPES_H_

    #include <SFML/Graphics.h>
    #include "app/types.h"
    #include "cjson/include/cjson.h"

    #define COMPONENTS_CONFIG "configs/components.json"

typedef struct s_list list_t;

/**
 * @brief Enum of buttons states
*/
typedef enum e_buttons_states {
    ST_BTN_INACTIVE = 0,
    ST_BTN_OVER,
    ST_BTN_ACTIVE,
    ST_BTN_DISABLE
} buttons_states_t;

/**
 * @brief Enum of levers states
*/
typedef enum e_levers_states {
    ST_LV_ON = 0,
    ST_LV_OFF
} levers_states_t;

/**
 * @brief Structure for a button.
 * It's majoritory use in a buttons list
*/
typedef struct s_button {
    char *title;
    char *description;
    float scale;
    sfColor color;
    sfTexture *texture;
    sfVector2f position;
    app_states_t app_state;
    buttons_states_t state;
} button_t;

/**
 * @brief Structure for a lever.
 * It's majoritory use in a levers list
*/
typedef struct s_lever {
    float scale;
    sfVector2f position;
    app_states_t app_state;
    levers_states_t state;
} lever_t;

/**
 * Structure with all components
*/
typedef struct s_components {
    list_t *buttons;
    list_t *levers;
} components_t;

#endif /* !COMPONENTS_TYPES_H_ */
