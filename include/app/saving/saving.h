/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** saving
*/

#ifndef SAVING_H_
    #define SAVING_H_

    #include <stdbool.h>
    #include "cjson/include/cjson.h"
    #include "types.h"

typedef struct s_app app_t;
typedef struct s_button button_t;

/**
 * @brief Ask user for saving at exiting app
 * @param app App object
 * @param window Window of app
 * @return Requirement status
 */
bool save_ask_on_exit(app_t *app, sfRenderWindow *window);

/**
 * @brief Ask file on which save game
 * @param app App object
 * @param saver Saver to use to save file
 */
void save_ask_file(app_t *app, saver_t *saver);

/**
 * @brief Load saved file to game
 * @param renderer Renderer object
 * @param app App object
 * @param button Clicked button
 */
int save_load_ask_file(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Export given inventory to export file
 * @param inventory Inventory to export
 * @param export Export file
 */
void save_export_inventory(list_t *inventory, cjson_t *export);

/**
 * @brief Export given competences to export file
 * @param competences Competences to export
 * @param export Export file
 */
void save_export_competences(list_t *competences, cjson_t *export);

/**
 * @brief Save player to export file
 * @param player Player to export
 * @param export Export file
 */
void save_player(player_t *player, cjson_t *export);

/**
 * @brief Save current game to file
 * @param app App object
 * @param filename Filename in which export game
 * @param notify Notify at end of saving
 * @param saver Saver used during saving step
 */
void save_save(app_t *app, char *filename, bool notify, saver_t *saver);

/**
 * @brief Save in game handler
 * @param renderer Renderer object
 * @param app App object
 * @param button Button clicked
 * @return Status of handler
 */
int save_in_game(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Create a new saver util
 * @return Created saver
 */
saver_t *saver_new(void);

/**
 * @brief Free given saver
 * @param saver Saver to free
 */
void saver_free(saver_t *saver);

/**
 * @brief Save quests to export file
 * @param quests Quests to export
 * @param export Export file
 */
void save_quests(app_quests_t *quests, cjson_t *export);

/**
 * @brief At file loading, check player fields
 * @param player Player to check
 * @param valid Status of checking validity
 */
void save_load_file_check_validity_player(cjson_t *player,
bool *valid);

/**
 * @brief Check validity of given file
 * @param file File to check
 * @return Status of file validity
 */
bool save_load_file_check_validity(cjson_t *file);

/**
 * @brief Restore inventory of player
 * @param player Player object
 * @param player_file Player parsed in saved file
 * @param items Items references of game
 */
void save_load_restore_player_inventory(player_t *player,
cjson_t *player_file, list_t *items);

/**
 * @brief Restore competences of player
 * @param player Player object
 * @param player_file Player parsed in saved file
 */
void save_load_restore_player_competences(player_t *player,
cjson_t *player_file);

/**
 * @brief Restore player object from given player_file
 * @param app App object
 * @param player_file Player file based on saved file
 */
void save_load_restore_player(app_t *app, cjson_t *player_file);

/**
 * @brief Restore quests object from given quests_file
 * @param app App object
 * @param quests_file Quests file based on saved file
 */
void save_load_restore_quests(app_t *app, cjson_t *quests_file);

/**
 * @brief Load file of saved game
 * @param app App object
 * @param filename File to load
 * @param renderer Renderer object
 */
void save_load(app_t *app, char *filename, renderer_t *renderer);

#endif /* !SAVING_H_ */
