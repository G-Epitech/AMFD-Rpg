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
    #include "types/renderer/types.h"

    #define NPC_CONFIG "configs/npcs.json"

/**
 * @brief Load given npc config into npcs list
 * @param npcs List of game npcs
 * @param config Config of npc to load in list
 */
void npc_load(list_t *npcs, cjson_t *config);

/**
 * @brief Load all npcs of game
 * @param renderer Renderer structure
 * @return Loaded list
 */
list_t *npcs_load(renderer_t *renderer);

/**
 * @brief Load npcs worlds data into npc
 * @param config Config to load
 * @param npc npc of which load worlds data
 * @return Status of success
 */
bool npc_load_worlds_data(cjson_array_t *config, npc_t *npc);

/**
 * @brief Load given config into worlds data of npc
 * @param config Configuration of current world for npc
 * @param worlds_data List of npc worlds data
 * @return Success of loading
 */
bool npc_load_world_data(cjson_t *config, list_t *worlds_data);

/**
 * @brief Load dialog for given world
 * @param dialogs Dialogs to load
 * @param world_data Data for given world
 */
void npc_load_world_dialogs(cjson_array_t *dialogs, npc_data_t *world_data);

/**
 * @brief Load enemy data if present
 * @param config Enemy CJSON data configuration
 * @param world_data Data for given world
 */
void npc_load_world_enemy(cjson_t *config, npc_data_t *world_data);

/**
 * @brief Destroy all worlds data of a npc
 * @param worlds_data Worlds data of npc to destroy
 */
void npc_destroy_worlds_data(list_t *worlds_data);

/**
 * @brief Destroy all npcs
 * @param npcs List of npcs to destroy
 */
void npcs_destroy(list_t *npcs);

/**
 * @brief Destroy given npc enemy data
 * @param enemy Enemy data to free
 */
void npc_destroy_world_enemy(npc_enemy_t *enemy);

/**
 * @brief Get data of expected world if exists
 * @param npc NPC of which get world data
 * @param world ID of world to get
 * @return Pointer to world data or NULL if npc is not in
 * given world
 */
npc_data_t * npc_get_data_of_world(npc_t *npc, worlds_t world);

/**
 * @brief Include NPCs to collisions array of worlds
 * @param renderer Renderer structure
 * @param npcs List of NPCs
 */
void npcs_include_to_array(renderer_t *renderer, list_t *npcs);

/**
 * @brief Get npc data by id of NPC
 * @param npcs List of npcs
 * @param id Id of the npc
 * @param world App world
 * @return npc_data_t* The data of the npc
 */
npc_data_t *npc_get_data_by_id(list_t *npcs, int id, worlds_t world);

#endif /* !NPC_H_ */
