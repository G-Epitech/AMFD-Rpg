/*
** EPITECH PROJECT, 2023
** loading.h
** File description:
** Loading screens functions
*/

#ifndef LOADING_H_
    #define LOADING_H_

    #include "types/renderer/types.h"

/**
 * @brief Displays the G-Epitech screen when window is launched
 * @param renderer Main renderer
*/
void loading_preload_screen(renderer_t *renderer);

/**
 * @brief Displays the text of what the program is loading
 * @param renderer Main renderer function
 * @param load_text Text of what the program is loading
*/
void load_screen_text_display(renderer_t *renderer, char *load_text);

/**
 * @brief Add a bar to load screen
 * @param renderer Main renderer function
 * @param stat Stat of the bar
 * @param info Info of the loading
 */
void load_screen_add_bar(renderer_t *renderer, int stat, char *load_text,
char *info);

/**
 * @brief Sleep function
 * @param time Time to sleep
 */
void loading_sleep(int time);

#endif /* !LOADING_H_ */
