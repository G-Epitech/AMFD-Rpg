/*
** EPITECH PROJECT, 2023
** display.h
** File description:
** Display functions
*/

#ifndef DISPLAY_H_
    #define DISPLAY_H_

    #include <SFML/Graphics.h>
    #include "types/renderer/types.h"
    #include "types/character/types.h"
    #include "app/display/types.h"

/**
 * @brief Display player on map
 * @param renderer Renderer object
 * @param app Application structure
 */
void display_player(renderer_t *renderer, app_t *app);

/**
 * @brief Display npcs of current world
 * @param renderer Renderer object
 * @param npcs List of npcs to display
 * @param world Current world ID
 */
void display_npcs_of_world(renderer_t *renderer, list_t *npcs,
worlds_t world);

/**
 * @brief Display a character at specified position with given skin
 * @param renderer Renderer object
 * @param position Position to set to character
 * @param skin_id ID of skin to set to given character
 * @param orientation Orientation of character
 */
void display_character(renderer_t *renderer, sfVector2f position,
int skin_id, skin_orientation_t orientation);

/**
 * @brief Display a map
 * @param texture Texture of the map
 * @param window Main window of the app
 * @param sprite A sprite where the texture will be render
*/
void display_map(sfTexture *texture, sfRenderWindow *window, sfSprite *sprite);

/**
 * @brief Display the back of a map
 * @param maps List of maps
 * @param window Main window of the app
 * @param sprite A sprite where the map will be render
 * @param world The specific world of the map
*/
void display_map_back(list_t *maps, sfRenderWindow *window, sfSprite *sprite,
worlds_t world);

/**
 * @brief Display the front of a map
 * @param maps List of maps
 * @param window Main window of the app
 * @param sprite A sprite where the map will be render
 * @param world The specific world of the map
*/
void display_map_front(list_t *maps, sfRenderWindow *window, sfSprite *sprite,
worlds_t world);

/**
 * @brief Handle the display of the application
 * @param renderer Renderer structure
 * @param app Application informations
*/
void display_handler(renderer_t *renderer, app_t *app);

/**
 * @biref Display buttons components
 * @param renderer Renderer structure
 * @param app Application informations
*/
void display_components_buttons(renderer_t *renderer, app_t *app);

/**
 * @biref Display all components
 * @param renderer Renderer structure
 * @param app Application informations
*/
void display_components(renderer_t *renderer, app_t *app);

/**
 * @brief Display backgrounds
 * @param renderer Renderer structure
 * @param app Application informations
*/
void display_components_backgrounds(renderer_t *renderer, app_t *app);

/**
 * @brief Display a button by icon
 * @param renderer Renderer structure
 * @param button The specific button
*/
void display_components_icon(renderer_t *renderer, button_t *button);

/**
 * @brief Display main menu
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_main_menu(renderer_t *renderer, app_t *app);

/**
 * @brief Display main menu
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_menus(renderer_t *renderer, app_t *app);

/**
 * @brief Display settings
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_settings(renderer_t *renderer, app_t *app);

/**
 * @brief Display levers
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_components_levers(renderer_t *renderer, app_t *app);

/**
 * @brief Dispatch display of buttons
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_buttons_dispatch(button_t *button, renderer_t *renderer);

/**
 * @brief Display button
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_button(button_t *button, renderer_t *renderer);

/**
 * @brief Display select character
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_select_character(renderer_t *renderer, app_t *app);

/**
 * @brief Display collisions box
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_developer_collisions(renderer_t *renderer, app_t *app);

/**
 * @brief Display position of the player
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_developer_position(renderer_t *renderer, app_t *app);
#endif /* !DISPLAY_H_ */
