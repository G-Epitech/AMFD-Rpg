/*
** EPITECH PROJECT, 2023
** assets.h
** File description:
** Assets functions
*/

#ifndef ASSETS_H_
    #define ASSETS_H_

    #include "types.h"

/**
 * @brief Free assets
 * @param assets Structures of assets
*/
void assets_free(assets_t *assets);

/**
 * @brief Load all assets from configs
 * @return The structure of assets (lists for any types of assets)
*/
assets_t *assets_load(void);

/**
 * @brief Load all maps from configs
 * @param maps List of maps
 * @warning All textures could be NULL.
 * Remember to check before using it in a sprite for example
*/
void maps_load(list_t *maps);

#endif /* !ASSETS_H_ */
