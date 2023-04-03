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

/**
 * @brief Free ressources
 * @param ressources Structures of ressources
*/
void ressources_free(ressources_t *ressources);

/**
 * @brief Free all maps data
 * @param maps List of maps
*/
void maps_free_data(list_t *maps);

/**
 * @brief Load all ressources from configs
 * @return The structure of ressources (lists for any types of ressources)
*/
ressources_t *ressources_load(void);

/**
 * @brief Load all maps from configs
 * @param maps List of maps
 * @warning All textures could be NULL.
 * Remember to check before using it in a sprite for example
*/
void maps_load(list_t *maps);

/**
 * @biref Init components ressources
 * @return components structure
*/
components_r_t *ressources_components_init(void);

/**
 * @brief Load all components ressources
 * @param components Structure of ressources components
 * @warning You must to previously init the components structure
*/
void ressources_components_load(components_r_t *components);

/**
 * @brief Load buttons textures
 * @param button_config Configuration of button texture
*/
button_r_t *ressources_components_button_load(cjson_t *button_config);

#endif /* !RESSOURCES_H_ */
