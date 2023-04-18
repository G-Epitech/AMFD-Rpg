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
    #include "app/network/types.h"
    #include "sound/types.h"

typedef struct s_list list_t;
typedef struct s_renderer renderer_t;
typedef struct s_npc_data npc_data_t;

typedef enum e_app_states {
    ST_LOADING = 0,         //Loading of the game
    ST_MAIN_MENU,           //Start menu
    ST_SETTINGS,            //Settings menu
    ST_HELP_1,              //Help menu 1
    ST_HELP_2,              //Help menu 2
    ST_GAMEMODE,            //Gamemode (solo/duo)
    ST_CONNEXIONMODE,       //Connexion mode (host/join)
    ST_CHOICE,              //Choice of the character
    ST_RESOLUTION,          //Choose the resolution of game
    ST_INGAME = 100,        //Main state, ingame player
    ST_INVENTORY = 300,     //Inventory menu
    ST_BREAK,               //Break menu (save/sound...)
    ST_FIGHT = 350,         //Fight interface
    ST_TASK = 500,          //Task delimiter
    ST_TASK_BASH,           //Task n°1: bash
    ST_TASK_BRUTEFORCE,     //Task n°2: brute force
    ST_TASK_FLIPPER,        //Task n°3: flipper
    ST_TASK_CAMERA,         //Task n°4: camera
    ST_QUIT = 1000          //Quit menu
} app_states_t;

typedef enum e_worlds {
    WL_VILLAGE = 0,
    WL_CITY
} worlds_t;

typedef struct s_control {
    int direction_nb;       //Number of directions (useful for diagonal moves)
    bool direction;         //Move direction
    sfVector2f offset;      //Move offset for the direction
    sfKeyCode key;          //Move key code
} control_t;

typedef struct s_settings {
    bool music;             //Music in game
    float volume;             //Volume of the music
    int fps;                //Framerate of the game
    bool full_screen;       //Application in full screen
    bool developer;         //Developer mode
} settings_t;

typedef union u_interaction_data {
    npc_data_t *npc;
} interaction_data_t;

typedef enum e_interaction_type {
    IT_NULL = 0,
    IT_NPC
} interaction_type_t;

typedef struct s_interactions {
    interaction_data_t data;
    interaction_type_t type;
    bool interaction;
} interactions_t;

typedef struct s_app {
    app_states_t state;     //State of the app
    worlds_t world;         //Actual wolrd where player is
    list_t *items;          //Items available in game
    list_t *players;        //List of players
    player_t *player;       //Player of the client
    player_t *partner;      //Partner player
    list_t *npcs;           //NPC of game
    control_t *control;     //Controller of the player
    list_t *tasks_setup;    //Taks of the game
    settings_t *settings;   //Settings of the application
    network_t *network;     //Network
    interactions_t *interaction;    //Interaction in the app
    sound_board_t *sound_board; //Soundboard
} app_t;

typedef bool (*app_init_member_t)(app_t *app, renderer_t *renderer);
typedef void (*app_free_member_t)(app_t *app);

#endif /* !APP_TYPES_H_ */
