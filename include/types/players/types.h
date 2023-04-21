/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Players types
*/

#ifndef PLAYERS_TYPES_H_
    #define PLAYERS_TYPES_H_

    #include <SFML/Graphics.h>

    #define PLAYER_DEFAULT_SPAWN ((sfVector2f) {42, 46})

typedef struct s_list list_t;
typedef struct s_skin skin_t;

/**
 * @brief Structure of a player
*/
typedef struct s_player {
    char *name;                 //Name of the player
    int xp;                     //Player exeprience
    int orientation;            //Orientation of the player
    sfVector2f position;        //Position of the player
    list_t *inventory;          //Inventory with all objects
    int skin_id;                //Skin ID
    int level;                  //Player level
    int life;                   //Life of the player
    int speed;                  //Speed of the player
    int intellect;              //Intelect of the player
    int map_stage;              //Map stage the player is currently in
} player_t;

#endif /* !PLAYERS_TYPES_H_ */
