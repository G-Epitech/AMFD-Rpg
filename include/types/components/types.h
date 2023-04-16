/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Components types
*/

#ifndef COMPONENTS_TYPES_H_
    #define COMPONENTS_TYPES_H_

    #include <SFML/Graphics.h>
    #include "app/app.h"
    #include "app/types.h"
    #include "app/utils/utils.h"
    #include "app/window/window.h"
    #include "cjson/include/cjson.h"
    #include "app/inventory/inventory.h"
    #include "app/settings/settings.h"
    #include "app/network/network.h"
    #include "app/tasks/bruteforce/bruteforce.h"

    #define COMPONENTS_CONFIG "configs/components.json"

typedef struct s_list list_t;
typedef struct s_renderer renderer_t;

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
    int id;
    char *title;
    char *description;
    float scale;
    int event;
    int next_state;
    bool developer;
    bool always_display;
    sfColor color;
    sfColor text_color;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f rect_scale;
    sfVector2f origin;
    app_states_t *app_state;
    buttons_states_t state;
    size_t state_size;
} button_t;

/**
 * @brief Structure for a lever.
 * It's majoritory use in a levers list
*/
typedef struct s_lever {
    int event;
    bool active;
    float scale;
    sfVector2f position;
    app_states_t app_state;
    levers_states_t state;
} lever_t;

// Colors of progress bar
typedef enum e_progress_colors {
    PG_RED,     // Red color
    PG_GREEN,   // Green color
    PG_BLUE,    // Blue color
    PG_YELLOW,  // Yellow color
    PG_BEIGE    // Beige color
} progress_colors_t;

// Progress bar
typedef struct s_progress {
    sfVector2f position;        // Position of progress bar
    progress_colors_t color;    // Color of progress bar
    sfVector2f size;            // Size of progress bar
    int sectors;                // Number of bar sectors
    int getter_value;           // Function to get value of completion
    app_states_t app_state;     // State of app on which display bar
} progress_t;

/**
 * Structure with all components
*/
typedef struct s_components {
    list_t *buttons;
    list_t *levers;
    list_t *progresses;
} components_t;

static const struct {
    int (*function) (renderer_t *renderer, app_t *app, button_t *button);
} event_button_map[] = {
    {test},
    {window_close},
    {states_switch_left},
    {states_switch_right},
    {settings_volume_malus},
    {settings_volume_up},
    {settings_fps_malus},
    {settings_fps_up},
    {developer_reload_json},
    {network_connexion_host},
    {network_connexion_join},
    {states_select_character},
    {brute_force_click}
};

static const struct {
    int (*function) (renderer_t *renderer, app_t *app, lever_t *lever);
} event_lever_map[] = {
    {settings_music},
    {settings_fullscreen},
    {settings_developer}
};

static const struct {
    int (*function) (renderer_t *renderer, app_t *app, progress_t *progress);
} event_progress_map[] = {
};

#endif /* !COMPONENTS_TYPES_H_ */
