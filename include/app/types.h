/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Application types
*/

#ifndef APP_TYPES_H_
    #define APP_TYPES_H_

    #include <stdbool.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include "types/players/types.h"
    #include "app/inventory/types.h"
    #include "app/network/types.h"
    #include "app/animations/types.h"
    #include "types/dialog_box/types.h"
    #include "sound/types.h"
    #include "app/quests/types.h"

    #define CURSOR_FILE "assets/components/cursor.png"
    #define NPC_COLOR sfYellow
    #define SHOP_COLOR sfRed
    #define ENTRY_COLOR sfBlue

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
    ST_SHOP = 200,          //Shop
    ST_INVENTORY = 300,     //Inventory menu
    ST_BREAK,               //Break menu (save/sound...)
    ST_IGSETTINGS,          //In game settings
    ST_IGHELP1,             //In game help 1
    ST_IGHELP2,             //In game help 2
    ST_IGRESOLUTION,        //In game resolution
    ST_SMSETTINGS,          //Side menu settings
    ST_SMHELP1,             //Side menu help1
    ST_SMHELP2,             //Side menu help2
    ST_SMRESOLUTION,        //Side menu resolution
    ST_IGSAVE,              //In game save
    ST_IGLOAD,              //In game load
    ST_IG_TREE_COMPETENCE,  //In game tree of competence
    ST_FIGHT = 350,         //Fight interface
    ST_DIALOGS = 400,       //Dialogs state
    ST_TASK = 500,          //Task delimiter
    ST_TASK_BASH,           //Task n°1: bash
    ST_TASK_BRUTEFORCE,     //Task n°2: brute force
    ST_TASK_FLIPPER,        //Task n°3: flipper
    ST_TASK_CAMERA,         //Task n°4: camera
    ST_QUIT = 1000          //Quit menu
} app_states_t;

typedef enum e_worlds {
    WL_VILLAGE = 0,
    WL_PLAYER_HOME_1,
    WL_PLAYER_HOME_2,
    WL_UNIVERSITY_1,
    WL_UNIVERSITY_2,
    WL_STORE,
    WL_PRISON,
    WL_MAIRIE_1,
    WL_MAIRIE_2,
    WL_MAIRIE_3,
    WL_MAIRIE_4,
    WL_HOSPITAL_1,
    WL_HOSPITAL_2,
    WL_HOSPITAL_3,
    WL_CITY,
    WL_AYMERIC
} worlds_t;

typedef struct shop_stock_s {
    item_t *curr_items;
    int *total_items;
    size_t total_items_len;
    size_t curr_items_len;
    sfTexture *item_grid;
    bool active;
} shop_stock_t;

typedef struct shop_s {
    int id;
    char *name;
    shop_stock_t *stock;
    worlds_t world;
    sfVector2f pos;
    int tile_len;
    int direction;
    sfClock *clock;
} shop_t;

typedef struct cursor_s {
    sfVector2f pos;
    sfTexture *texture;
} cursor_t;

typedef struct s_control {
    int direction_nb;       //Number of directions (useful for diagonal moves)
    bool direction;         //Move direction
    sfVector2f offset;      //Move offset for the direction
    sfKeyCode key;          //Move key code
    cursor_t *cursor;
} control_t;

typedef struct s_settings {
    bool music;             //Music in game
    float volume;             //Volume of the music
    int fps;                //Framerate of the game
    bool full_screen;       //Application in full screen
    bool developer;         //Developer mode
} settings_t;

typedef enum e_fight_state {
    FT_CHOICE = 0,
    FT_PLAYER_ATTACK,
    FT_WAIT,
    FT_NPC_ATTACK,
    FT_END
} fight_state_t;

typedef struct s_fight {
    npc_data_t *npc;
    fight_state_t state;
    int choice;
    int mana;
    int enemy_life;
    int round;
} fight_t;

typedef struct s_interaction_dialogs {
    npc_data_t *npc;
    int index;
} interaction_dialogs_t;

typedef union u_interaction_data {
    npc_data_t *npc;
    fight_t *fight;
    interaction_dialogs_t *dialogs;
    int entry_id;
    int shop_id;
} interaction_data_t;

typedef enum e_interaction_type {
    IT_NULL = 0,
    IT_NPC,
    IT_DIALOGS,
    IT_FIGHT,
    IT_TRAVEL,
    IT_SHOP
} interaction_type_t;

typedef struct s_interactions {
    interaction_data_t data;
    interaction_type_t type;
    int value;
    bool active;
    bool interaction;
} interactions_t;

typedef struct s_app {
    app_states_t state;                 //State of the app
    app_states_t prev_state;            //Previous state of the game
    worlds_t world;                     //Actual wolrd where player is
    list_t *items;                      //Items available in game
    list_t *players;                    //List of players
    player_t *player;                   //Player of the client
    player_t *partner;                  //Partner player
    list_t *npcs;                       //NPC of game
    control_t *control;                 //Controller of the player
    list_t *tasks_setup;                //Tasks of the game
    settings_t *settings;               //Settings of the application
    network_t *network;                 //Network
    interactions_t *interaction;        //Interaction in the app
    inventory_event_t *inventory_event; //Inventory move
    dialog_box_t *dialog_box;           //Dialog box
    animations_t *animations;           //Animations in the app
    sound_board_t *sound_board;         //Soundboard
    list_t *player_anim;                //Player animations
    app_quests_t *quests;               //Quests of the game
    sfClock *clock;                     //Clock of the game
    list_t *shops;                      //Shops of the game
} app_t;

typedef bool (*app_init_member_t)(app_t *app, renderer_t *renderer);
typedef void (*app_free_member_t)(app_t *app);

#endif /* !APP_TYPES_H_ */
