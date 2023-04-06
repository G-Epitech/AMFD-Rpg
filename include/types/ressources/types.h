/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Ressources types
*/

#ifndef RESSOURCES_TYPES_H_
    #define RESSOURCES_TYPES_H_

    #include <SFML/Graphics.h>
    #include "app/types.h"

    #define RESSOURCES_MAPS_CONFIG "configs/ressources/maps.json"
    #define RESSOURCES_SKINS_CONFIG "configs/skins.json"
    #define RESSOURCES_SKINS_RECT ((sfVector2i) { 16, 32 })
    #define RESSOURCES_COMPONENTS_CONFIG "configs/ressources/components.json"

typedef struct s_list list_t;

/**
 * @brief Structure of a skin
*/
typedef struct s_skin {
    int id;                 //Id of the skin
    sfTexture *texture;     //Texture of corresponding to skin
} skin_t;

/**
 * @brief Structure of a map
*/
typedef struct s_map {
    worlds_t world;         //Id of the world where the map must be display
    int **collision_layer;  //Collision layer for the player
    sfTexture *back;        //Texture of the back of the map
    sfTexture *front;       //Texture of the front of the map
} map_t;

/**
 * @biref Structure of a button ressource
*/
typedef struct s_button_r {
    sfTexture *left;        //Left texture (first part)
    sfTexture *right;       //Middle texture (second part)
    sfTexture *middle;      //Right texture (last part)
} button_r_t;

/**
 * @brief Structure of background
*/
typedef struct s_background {
    sfTexture *texture;     //Texture of the background
    float scale;            //Scale of the background
    app_states_t app_state; //State when the background must be display
    sfVector2f position;    //Position of the background
} background_t;

/**
 * @biref Structure with components ressources
*/
typedef struct s_components_r {
    button_r_t *button;         //Button textures
    list_t *backgrounds;        //Backgrounds list
} components_r_t;

/**
 * @brief Structure of ressources (textures)
*/
typedef struct s_ressources {
    list_t *maps;               //List of maps (textures)
    list_t *skins;              //List of skins (textures)
    list_t *props;              //List of props (textures)
    components_r_t *components; //Structure of components ressources
} ressources_t;

#endif /* !RESSOURCES_TYPES_H_ */
