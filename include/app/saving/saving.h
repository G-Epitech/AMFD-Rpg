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
 */
void save_save(app_t *app, char *filename, bool notify);

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

#endif /* !SAVING_H_ */
