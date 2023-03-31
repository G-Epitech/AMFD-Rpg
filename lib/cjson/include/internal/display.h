/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** display
*/

#ifndef CJSON_INTERNAL_DISPLAY_H_
    #define CJSON_INTERNAL_DISPLAY_H_

    #include "types.h"

    #define CJSON_INTERNAL_COLOR_RESET "\033[0m"
    #define CJSON_INTERNAL_RED "\033[0;31m"
    #define CJSON_INTERNAL_GREEN "\033[0;32m"
    #define CJSON_INTERNAL_YELLOW "\033[0;33m"
    #define CJSON_INTERNAL_BLUE "\033[0;34m"
    #define CJSON_INTERNAL_PURPLE "\033[0;35m"
    #define CJSON_INTERNAL_CYAN "\033[0;36m"

/**
 * @brief Display given CJSON element
 * @param cjson CJSON element to display
 * @param depth Depth of display
 * @param error Error status
 */
void internal_cjson_display(cjson_t *cjson, int depth, bool *error);

/**
 * @brief Display tabs for depth
 * @param depth Depth of display
 */
void internal_cjson_display_add_tabs(int depth);

/**
 * @brief Display given CJSON element
 * @param cjson CJSON element to display
 * @param depth Depth of display
 * @param error Error status
 */
void internal_cjson_display(cjson_t *cjson, int depth, bool *error);

/**
 * @brief Display given CJSON element as an array
 * @param cjson CJSON element to display
 * @param depth Depth of display
 * @param error Error status
 */
void internal_cjson_display_array(cjson_t *cjson, int depth, bool *error);

/**
 * @brief Display given CJSON element as an object
 * @param cjson CJSON element to display
 * @param depth Depth of display
 * @param error Error status
 */
void internal_cjson_display_object(cjson_t *cjson, int depth, bool *error);

/**
 * @brief Display given CJSON element as a string
 * @param cjson CJSON element to display
 * @param depth Depth of display
 * @param error Error status
 */
void internal_cjson_display_string(cjson_t *cjson);

/**
 * @brief Display given CJSON element as a number
 * @param cjson CJSON element to display
 * @param depth Depth of display
 * @param error Error status
 */
void internal_cjson_display_number(cjson_t *cjson);

/**
 * @brief Display given CJSON element as a bool
 * @param cjson CJSON element to display
 * @param depth Depth of display
 * @param error Error status
 */
void internal_cjson_display_bool(cjson_t *cjson);

/**
 * @brief Display given CJSON element as null
 */
void internal_cjson_display_null(void);

#endif /* !CJSON_INTERNAL_DISPLAY_H_ */
