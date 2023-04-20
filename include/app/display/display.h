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
    #include "types/characters/types.h"

    #define SIZE_UP(pos, scale) ((sfVector2f) {pos.x * scale, pos.y * scale})
    #define MIDDLE_POS(size, middle) ((sfVector2f)\
    {size.x + middle.x, middle.y})
    #define RIGHT_POS(size, middle, right, scale) ((sfVector2f)\
    {size.x + middle.x * scale+ right.x, right.y})
    #define GAME_TITLE "Hackers Quests"
    #define SETTINGS_TITLE "Settings"

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
 * @biref Display interaction icon
 * @param renderer Renderer structure
 * @param app Application informations
*/
void display_components_interaction(renderer_t *renderer, app_t *app);

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
 * @brief Call all buttons displayers
 * @param button Button to display
 * @param renderer Renderer object
 */
void display_buttons_dispatch(button_t *button, renderer_t *renderer);

/**
 * @brief Display give button
 * @param button Button to display
 * @param renderer Renderer object
 */
void display_button(button_t *button, renderer_t *renderer);

/**
 * @brief Display inventory of game
 * @param renderer Renderer object
 * @param app App object
 */
void display_inventory(renderer_t *renderer, app_t *app);

/**
 * @brief Display character selector
 * @param renderer Renderer object
 * @param app App object
 */
void display_select_character(renderer_t *renderer, app_t *app);

/**
 * @brief Display box of an inventory item
 * @param renderer Renderer object
 * @param i Index of item for which set box
 * @param active Specify if item is in active inventory grid
 * @param empty Specify if given box is occuped by an item
 */
void display_inventory_item_box(renderer_t *renderer, size_t i,
bool active, bool empty);

/**
 * @brief Display box of an inventory item at given position
 * @param renderer Renderer object
 * @param position Position on which display given box
 * @param active Specify if item is in active inventory grid
 * @param empty Specify if given box is occuped by an item
 */
void display_inventory_item_box_at_pos(renderer_t *renderer,
sfVector2f position, bool active, bool empty);

/**
 * @brief Get position of given item
 * @param i Index of item in inventory
 * @param active Active status
 * @param position Position pointer in which set obtained position
 */
void display_inventory_get_item_position(size_t i, bool active,
sfVector2f *position);

/**
 * @brief Display inventory grids
 * @param renderer Renderer object
 * @param app App object
 */
void display_inventory_grids(renderer_t *renderer, app_t *app);

/**
 * @brief Display empty boxes on grids
 * @param renderer Renderer object
 * @param actives_boxes Actives boxes occupation array
 * @param main_boxes Main boxes occupation array
 * @param event Inventory event
 */
void display_inventory_grids_empty(renderer_t *renderer, int *actives_boxes,
int *main_boxes, inventory_event_t *event);

/**
 * @brief Display taken boxes on grids
 * @param renderer Renderer object
 * @param inventory Inventory of player
 * @param event Event on inventory
 */
void display_inventory_grids_taken(renderer_t *renderer, list_t *inventory,
inventory_event_t *event);

/**
 * @brief Display specials element on grids
 * @param renderer Renderer object
 * @param event Event of inventory
 */
void display_inventory_grids_specials(renderer_t *renderer,
inventory_event_t *event);

/**
 * @brief Display player profile in inventory
 * @param renderer Renderer object
 * @param app App object
 */
void display_inventory_profile(renderer_t *renderer, app_t *app);

/**
 * @brief Display content of item
 * @param renderer Renderer object
 * @param item Item to display
 * @param event Inventory event
 */
void display_inventory_item_content(renderer_t *renderer,
inventory_item_t *item, inventory_event_t *event);

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

/**
 * @brief Display fights menus
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_fight(renderer_t *renderer, app_t *app);

/**
 * @brief Display fights choice box
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_fight_choice(renderer_t *renderer, app_t *app);

/**
 * @brief Display fights attack box
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_fight_attack(renderer_t *renderer, app_t *app);

/**
 * @brief Display floating text animations
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_animations_floating_text(renderer_t *renderer, app_t *app);

/**
 * @brief Display animations
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_animations(renderer_t *renderer, app_t *app);

/**
 * @brief Display notif animation
 * @param renderer Renderer structure
 * @param app Application informations
 */
void display_animations_notif(renderer_t *renderer, app_t *app);

/*
 * @brief Display progress bar component
 * @param progress Progress bar component
 * @param renderer Renderer object
 * @param app App object
 */
void display_progress(progress_t *progress, renderer_t *renderer, app_t *app);

/**
 * @brief Display all progress bars
 * @param renderer Renderer object
 * @param app App object
 */
void display_components_progresses(renderer_t *renderer, app_t *app);

/**
 * @brief Display inventory levels
 * @param renderer Renderer object
 * @param app App object
 */
void display_inventory_levels(renderer_t *renderer, app_t *app);

/**
 * @brief Display masks on given item
 * @param renderer Renderer object
 * @param item Item object
 * @param position Position of item
 * @param scale Scale of item
 */
void inventory_display_item_masks(renderer_t *renderer, item_t *item,
sfVector2f position, float scale);

/**
 * @brief Display given dialog box
 * @param renderer Renderer object
 * @param dialog_box Dialog box to display
 */
void display_dialog_box(renderer_t *renderer, dialog_box_t *dialog_box);

/**
 * @brief Display options of dialog box
 * @param renderer Renderer object
 * @param dialog_box Dialog box
 */
void display_dialog_box_options(renderer_t *renderer,
dialog_box_t *dialog_box);

/**
 * @brief Display NPC dialogs
 * @param renderer Renderer object
 * @param app App object
 */
void display_dialogs(renderer_t *renderer, app_t *app);

#endif /* !DISPLAY_H_ */
