/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** script_bash
*/

#ifndef SCRIPT_BASH_H_
    #define SCRIPT_BASH_H_

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>
    #include "types/list/types.h"

/**
 * @brief Create the node for task bash
*/
node_t *task_create_nodes_bash(void);

/**
 * @brief Create list of struct for tasks
*/
list_t *task_create(void);

/**
 * @brief Display handler of task bash
 * @param renderer Main renderer function
 * @param app Application structure
*/
void app_task_bash_display(renderer_t *renderer, app_t *app);

/**
 * @brief Core handler of task bash
 * @param app Application structure
*/
int app_task_bash_core(app_t *app, renderer_t *renderer);

/**
 * @brief Init task bash when first entrance
 * @param app Application structure
*/
int init_task_bash(app_t *app);

/**
 * @brief Add a char to cmd who was writing
 * @param event The event
 * @param app Application structure
*/
void cmd_write(sfEvent event, app_t *app);

/**
 * @brief Handle if after enter its a win or loose
 * @param event The event
 * @param app Application structure
*/
void good_or_bad_result(sfEvent event, app_t *app, renderer_t *renderer);

/**
 * @brief Find the node relative to index_cmd
 * @param list The list of command
 * @param index_cmd Index of current command
*/
node_t *find_node_cmd(list_t *list, int index_cmd);

/**
 * @brief Reset setup of bash struct when its finish
 * @param app Application structure
*/
void reset_setup_bash(app_t *app);

/**
 * @brief Find the node relative to index_cmd
 * @param list The list of prompt
 * @param object_file file object of position
*/
int init_list_prompt(list_t *prompt, cjson_t *object_file);

/**
 * @brief Find the node relative to index_cmd
 * @param list The list of cmd
 * @param object_file file object of position
*/
int init_list_cmd(list_t *cmd, cjson_t *object_file);

/**
 * @brief Find the node relative to index_cmd
 * @param list The list of cmd model
 * @param object_file file object of position
*/
int init_list_cmd_model(list_t *cmd_model, cjson_t *object_file);

#endif /* !SCRIPT_BASH_H_ */
