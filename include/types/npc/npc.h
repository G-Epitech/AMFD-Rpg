/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** npc
*/

#ifndef NPC_H_
    #define NPC_H_

    #include "types/npc/types.h"
    #include "cjson/include/cjson.h"

    #define NPC_CONFIG "configs/npcs.json"

/**
 * @brief Load given npc config into npcs list
 * @param npcs List of game npcs
 * @param config Config of npc to load in list
 */
void npc_load(list_t *npcs, cjson_t *config);

/**
 * @brief Load all npcs of game
 * @return Loaded list
 */
list_t *npcs_load(void);

/**
 * @brief Load npcs worlds data into npc
 * @param config Config to load
 * @param npc npc of which load worlds data
 * @return Status of success
 */
bool npc_load_worlds_data(cjson_array_t *config, npc_t *npc);

/**
 * @brief Load dialog for given world
 * @param dialogs Dialogs to load
 * @param world_data Data for given world
 */
void npc_load_world_dialogs(cjson_array_t *dialogs, npc_data_t *world_data);

#endif /* !NPC_H_ */
