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
 * @brief Free all maps
 * @param maps List of maps
*/
void maps_free(list_t *maps);

/**
 * @brief Load all skins from configs
 * @param skins List of skins
 * @warning All textures could be NULL.
 * Remember to check before using it in a sprite for example
 */
void skins_load(list_t *skins);

/**
 * @brief Free all skins
 * @param maps List of skins
*/
void skins_free(list_t *skins);

#endif /* !RESSOURCES_H_ */
