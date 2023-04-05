/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Players types
*/

#ifndef PLAYERS_TYPES_H_
    #define PLAYERS_TYPES_H_

    #include <SFML/Graphics.h>

    #define PLAYER_DEFAULT_SPAWN ((sfVector2f) {3000, 3000})

typedef struct s_list list_t;
typedef struct s_skin skin_t;

/**
 * @brief Structure of a player
*/
typedef struct s_player {
    char *name;                 //Name of the player
    int xp;                     //Player exeprience
    sfVector2f position;        //Position of the player
    sfVector2f colision_pos;    //Position of the player in the colision layer
    list_t *inventory;          //Inventory with all objects
    skin_t *skin;               //Representation of the player (visual)
} player_t;

#endif /* !PLAYERS_TYPES_H_ */
