/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Players types
*/

#ifndef PLAYERS_TYPES_H_
    #define PLAYERS_TYPES_H_

    #include <SFML/Graphics.h>

    #define PLAYER_DEFAULT_SPAWN ((sfVector2f) {1000, 1015})

typedef struct s_list list_t;

typedef enum e_entity_state {
    IDLE,
    WALKING
} enitity_state_t;

/**
 * @brief Structure of a player
*/
typedef struct s_player {
    char *name;                 //Name of the player
    int xp;                     //Player exeprience
    int orientation;            //Orientation of the player
    sfVector2f position;        //Position of the player
    enitity_state_t state;      //State of the player
    list_t *inventory;          //Inventory with all objects
    sfIntRect rect;             //Player rect
    int skin_id;                //Skin ID
    int level;                  //Player level
    int life;                   //Life of the player
    int speed;                  //Speed of the player
    int intellect;              //Intelect of the player
    int credits;                //Credit of player for earn competence
    list_t *competences;        //competence tree of the player
    int life_max;               //Life max of the player
    int speed_max;              //Speed max of the player
    int intellect_max;          //Intelect max of the player
    int xp_max;          //Intelect max of the player
} player_t;

#endif /* !PLAYERS_TYPES_H_ */
