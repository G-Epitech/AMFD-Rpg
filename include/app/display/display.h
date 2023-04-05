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
void display_handle(renderer_t *renderer, app_t *app);
#endif /* !DISPLAY_H_ */
