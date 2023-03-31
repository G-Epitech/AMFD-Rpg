/*
** EPITECH PROJECT, 2023
** players.h
** File description:
** Players functions
*/

#ifndef PLAYERS_H_
    #define PLAYERS_H_

    #include "types/players/types.h"

/**
 * @brief Initialisation of a player list
 * @return New list of players
*/
list_t *players_list_init(void);

/**
 * @brief Add a new player
 * @param list List of players
 * @param name Name of the new player
 * @return Structure of the new player
*/
player_t *players_add(list_t *list, char *name);

#endif /* !PLAYERS_H_ */
