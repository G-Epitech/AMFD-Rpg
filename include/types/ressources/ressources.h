/*
** EPITECH PROJECT, 2023
** ressources.h
** File description:
** ressources functions
*/

#ifndef RESSOURCES_H_
    #define RESSOURCES_H_

    #include "types.h"
    #include "types/list/types.h"

typedef struct s_renderer renderer_t;
typedef struct s_icons_competences icons_competences_t;

/**
 * @brief Free ressources
 * @param ressources Structures of ressources
*/
void ressources_free(ressources_t *ressources);

/**
 * @brief Load all ressources from configs
 * @return The structure of ressources (lists for any types of ressources)
*/
ressources_t *ressources_load(renderer_t *renderer);

/**
 * @brief Load all maps from configs
 * @param maps List of maps
 * @warning All textures could be NULL.
 * Remember to check before using it in a sprite for example
*/
void maps_load(list_t *maps, renderer_t *renderer);

/**
 * @brief Free all maps
 * @param maps List of maps
*/
void maps_free(list_t *maps);

/**
 * @brief Loads list of entries for a map
 * @param map Map
 * @param map_config Map config
 * @return List of entries
*/
list_t *map_load_entry(cjson_t *map_config);

/**
 * @brief Create all the collision map textures to see in dev mode
 * @param maps List of maps
*/
void map_charge_collision_textures(list_t *maps);

/**
 * @brief Draws the entries on the collision layer
 * @param maps Maps list
*/
void entry_include_to_array(list_t *maps);

/**
 * @brief Load all skins from configs
 * @param renderer Renderer object
 * @param skins List of skins
 * @warning All textures could be NULL.
 * Remember to check before using it in a sprite for example
 */
void skins_load(renderer_t *renderer, list_t *skins);

/**
 * @brief Free all skins
 * @param maps List of skins
*/
void skins_free(list_t *skins);

/**
 * @brief Get expected skin
 * @param skins Skins ressources
 * @param skin_id ID of skin to get
 * @return Expected skin or NULL if not found
 */
const skin_t *ressources_get_skin(list_t *skins, int skin_id);

/**
 * @brief Init components ressources
 * @param renderer Renderer object
 * @return components structure
*/
components_r_t *ressources_components_init(renderer_t *renderer);

/**
 * @brief Load all components ressources
 * @param renderer Renderer object
 * @param components Structure of ressources components
 * @warning You must to previously init the components structure
*/
void ressources_components_load(renderer_t *renderer,
components_r_t *components);

/**
 * @brief Load buttons textures
 * @param button_config Configuration of button texture
*/
button_r_t *ressources_components_button_load(cjson_t *button_config);

/**
 * @brief Load backgrounds assets
 * @param backgrounds_config Json array of backgrounds
 * @return List of backgrounds
*/
list_t *ressources_components_backgrounds_load(cjson_array_t
*backgrounds_config);

/**
 * @brief Load levers textures
 * @param lever_config Configuration of lever texture
*/
lever_r_t *ressources_components_lever_load(cjson_t *lever_config);

/**
 * @brief Load texture for progress bars
 * @param config Configuration file at CSJON format
 * @return Created texture
 */
sfTexture *ressources_components_progress_load(cjson_t *config);

/**
 * @brief Load texture for dialog box bars
 * @param config Configuration file at CSJON format
 * @return Created texture
 */
sfTexture *ressources_components_dialog_box_load(cjson_t *config);

/**
 * @brief Load inventory ressources
 * @param renderer Renderer object
 * @param inventory Structure of inventory ressources
 */
void inventory_load(renderer_t *renderer, inventory_r_t *inventory);

/**
 * @brief Load items texture
 * @param renderer Renderer object
 * @param ressources Resssources of app
 */
void items_texture_load(renderer_t *renderer, ressources_t *ressources);

/**
 * @brief Load icons ressources
 * @param renderer Renderer object
 * @param inventory Structure of icons ressources
 */
void icons_load(renderer_t *renderer, icons_r_t *icons);

/**
 * @brief Load icons ressources
 * @param tree Tree struct of texture
 * @param config Configuration file at CSJON format
 */
void icons_load_data_competence(icons_competences_t *tree, cjson_t *configs);

/**
 * @brief Load fight components
 * @param config Config of fight
 */
list_t *ressources_components_fight_load(cjson_t *config);

/**
 * @brief Load all animations from configs
 * @param renderer Renderer object
 * @param animations List of animations
 */
void animations_load(renderer_t *renderer, list_t *animations);

#endif /* !RESSOURCES_H_ */
