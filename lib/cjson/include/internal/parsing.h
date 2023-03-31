/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** parsing
*/

#ifndef CJSON_INTERNAL_PARSING_H_
    #define CJSON_INTERNAL_PARSING_H_

    #include <stddef.h>
    #include "types.h"

/**
 * @brief Parse json object
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed object
 */
cjson_value_t internal_cjson_parse_object(char *json, int *i, bool *error);

/**
 * @brief Parse json array
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed array
 */
cjson_value_t internal_cjson_parse_array(char *json, int *i, bool *error);

/**
 * @brief Parse json string
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed string
 */
cjson_value_t internal_cjson_parse_string(char *json, int *i, bool *error);

/**
 * @brief Parse json number
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed number
 */
cjson_value_t internal_cjson_parse_number(char *json, int *i, bool *error);

/**
 * @brief Parse json boolean
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed boolean
 */
cjson_value_t internal_cjson_parse_bool(char *json, int *i, bool *error);

/**
 * @brief Parse json null
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed null
 */
cjson_value_t internal_cjson_parse_null(char *json, int *i, bool *error);

/**
 * @brief Get value of next item and set it in CJSON element
 * @param cjson CJSON element in which set value
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 */
void internal_cjson_get_value(cjson_t *cjson, char *json,
int *i, bool *error);

/**
 * @brief Check if next char is an JSON object separator
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 */
void internal_cjson_check_separator(char *json, int *i, bool *error);

/**
 * @brief Get key in JSON object
 * @param json JSON string
 * @param i Current index
 * @param error Error status
 * @return Parsed key
 */
char *internal_cjson_parse_key(char *json, int *i, bool *error);

/**
 * @brief Skip blank spaces
 * @param json JSON content
 * @param i Index of current position
 */
void internal_cjson_skip_blank(char *json, int *i);

/**
 * @brief Get size of file if exists
 * @param filepath File of which get size
 * @return Size of file
 */
off_t internal_cjson_file_get_size(char *filepath);

#endif /* !CJSON_INTERNAL_PARSING_H_ */
