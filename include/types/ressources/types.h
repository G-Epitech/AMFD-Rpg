/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Ressources types
*/

#ifndef RESSOURCES_TYPES_H_
    #define RESSOURCES_TYPES_H_

    #include <SFML/Graphics.h>

    #define RESSOURCES_MAPS_CONFIG "configs/maps.json"
    #define RESSOURCES_SKINS_CONFIG "configs/skin.json"

typedef struct s_list list_t;

/**
 * @brief Structure of a skin
*/
typedef struct s_skin {
    int id;                 //Id of the skin
} skin_t;

/**
 * @brief Structure of a map
*/
typedef struct s_map {
    int world;              //Id of the world where the map must be display
    sfTexture *back;        //Texture of the back of the map
    sfTexture *front;       //Texture of the front of the map
} map_t;

/**
 * @brief Structure of ressources (textures)
*/
typedef struct s_ressources {
    list_t *maps;           //List of maps (textures)
    list_t *skins;          //List of skins (textures)
    list_t *props;          //List of props (textures)
} ressources_t;

#endif /* !RESSOURCES_TYPES_H_ */
