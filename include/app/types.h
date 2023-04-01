/*
** EPITECH PROJECT, 2023
** types.h
** File description:
** Application types
*/

#ifndef APP_TYPES_H_
    #define APP_TYPES_H_

typedef enum e_app_states {
    ST_LOADING = 0,         //Loading of the game
    ST_MAIN_MENU,           //Start menu
    ST_INGAME,              //Main state, ingame player
    ST_INVENTORY,           //Inventory menu
    ST_FIGHT,               //Fight interface
    ST_BREAK,               //Break menu (save/sound...)
    ST_TASK = 50,           //Task delimiter
    ST_TASK_BASH,           //Task n°1: bash
    ST_QUIT = 100           //Quit menu
} app_states_t;

typedef struct s_app {
    app_states_t state;         //State of the app
} app_t;

#endif /* !APP_TYPES_H_ */
