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

    #define RESSOURCES_SKINS_CONFIG "configs/skins.json"
    #define RESSOURCES_SKINS_RECT ((sfVector2i) { 16, 32 })
    #define RESSOURCES_MAPS_CONFIG "configs/ressources/maps.json"
    #define RESSOURCES_MAPS_CONFIG "configs/ressources/maps.json"
    #define RESSOURCES_ANIMATIONS_CONFIG "configs/animations/environment.json"
    #define RESSOURCES_INVENTORY_CONFIG "configs/ressources/inventory.json"
    #define RESSOURCES_COMPONENTS_CONFIG "configs/ressources/components.json"
    #define RESSOURCES_COMPONENTS_FIGHT_CONFIG "configs/fight/attacks.json"
    #define RESSOURCES_ICONS_CONFIG "configs/ressources/icons.json"

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
    sfTexture *back;        //Texture of the back of the map
    sfTexture *front;       //Texture of the front of the map
    sfImage *collision;     //Image of collision
} map_t;

/**
 * @brief Structure of a animations
*/
typedef struct s_anim {
    worlds_t world;             //Id of the world where the map must be display
    sfTexture *asset;            //Texture of asset
    sfImage *collision;         //Image of collision
    float off_set;              //Number offset of asset
    float speed;                //Number of speed animation
    sfVector2f position;        //Position texture
    sfIntRect back;             //Back rect of 
} anim_t;

/**
 * @biref Structure of a button ressource
*/
typedef struct s_button_r {
    sfTexture *left;        //Left texture (first part)
    sfTexture *right;       //Middle texture (second part)
    sfTexture *middle;      //Right texture (last part)
} button_r_t;

/**
 * @biref Structure of a button ressource
*/
typedef struct s_lever_r {
    sfTexture *on;        //On texture (first part)
    sfTexture *off;       //Off texture (second part)
} lever_r_t;

/**
 * @brief Structure of background
*/
typedef struct s_background {
    sfTexture *texture;         //Texture of the background
    float scale;                //Scale of the background
    app_states_t *app_state;    //State when the background must be display
    size_t state_size;          //Size of state array
    sfVector2f position;        //Position of the background
} background_t;

typedef struct s_attack {
    sfTexture *texture;
    sfVector2f position;
    char *title;
    int level;
    int mana;
    int damage;
    bool shake;
} attack_t;

/**
 * @biref Structure with components ressources
*/
typedef struct s_components_r {
    button_r_t *button;         //Button textures
    lever_r_t *lever;           //Lever textures
    list_t *backgrounds;        //Backgrounds list
    list_t *fight;              //Fight ressources (attaks)
    sfTexture *progress;        //Texture for progress bars
    sfTexture *dialog_box;      //Texture for dialog boxes
} components_r_t;

typedef struct s_inventory_ressources {
    sfTexture *grid;            //Grid utils texture
    sfTexture *items;           //Inventory items texture
} inventory_r_t;

typedef struct s_icons_ressources {
    sfTexture *valid;           //Valid icon
    sfTexture *refuse;          //Refuse icon
    sfTexture *attack_lock;     //Refuse icon
    sfTexture *selector_false;  //Selector false icon
    sfTexture *selector_true;   //Selector true icon
    sfTexture *interaction;     //Interaction info icon
    sfTexture *notif;           //Notif icon
    sfTexture *happy;           //Happy icon
    sfTexture *hungry;          //Hungry icon
    sfTexture *xp;              //XP icon
} icons_r_t;

/**
 * @brief Structure of ressources (textures)
*/
typedef struct s_ressources {
    list_t *maps;                       //List of maps (textures)
    list_t *skins;                      //List of skins (textures)
    list_t *props;                      //List of props (textures)
    list_t *animations;                 //List of animation
    sfTexture *items;                   //Texture of items
    inventory_r_t *inventory;           //Structure of inventory ressources
    components_r_t *components;         //Structure of components ressources
    icons_r_t *icons;                   //Structure of icons ressources
} ressources_t;

#endif /* !RESSOURCES_TYPES_H_ */
