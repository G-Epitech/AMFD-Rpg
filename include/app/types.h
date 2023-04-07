/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Application types
*/

#ifndef APP_TYPES_H_
    #define APP_TYPES_H_

    #include <stdbool.h>
    #include "types/players/types.h"

typedef struct s_list list_t;

typedef enum e_app_states {
    ST_LOADING = 0,         //Loading of the game
    ST_MAIN_MENU,           //Start menu
    ST_SETTINGS,            //Settings menu
    ST_HELP_1,              //Help menu 1
    ST_HELP_2,              //Help menu 2
    ST_BREAK,               //Break menu (save/sound...)
    ST_INVENTORY = 25,      //Inventory menu
    ST_INGAME = 30,         //Main state, ingame player
    ST_INBUILDING,          //In building
    ST_FIGHT = 40,          //Fight interface
    ST_TASK = 50,           //Task delimiter
    ST_TASK_BASH,           //Task n°1: bash
    ST_TASK_BRUTEFORCE,     //Task n°2: bruteforce
    ST_QUIT = 100           //Quit menu
} app_states_t;

typedef enum e_worlds {
    WL_VILLAGE = 0,
    WL_CITY
} worlds_t;

typedef struct s_control {
    bool direction;         //Move direction
    sfVector2f offset;      //Move offset for the direction
    sfKeyCode key;          //Move key code
} control_t;

typedef struct s_app {
    app_states_t state;     //State of the app
    worlds_t world;         //Actual wolrd where player is
    list_t *players;        //List of players
    player_t *player;       //Player of the client
    list_t *npcs;           //NPC of game
    control_t *control;     //Controller of the player
    list_t *tasks_setup;
} app_t;

#endif /* !APP_TYPES_H_ */
