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

#endif /* !RESSOURCES_H_ */
