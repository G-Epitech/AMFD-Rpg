/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** stringify
*/

#ifndef CJSON_INTERNAL_STRINGIFY_H_
    #define CJSON_INTERNAL_STRINGIFY_H_

    #include <sys/types.h>
    #include "types.h"

/**
 * @brief Get rendering size of given array
 * @param cjson Array CJSON element to stringify
 * @param size Size of rendered string
 * @param depth Depth of object
 * @param error Error status
 */
void internal_cjson_string_size_array(cjson_t *cjson, size_t *size,
int depth, bool *error);

/**
 * @brief Get rendering size of given number
 * @param cjson Number CJSON element to stringify
 * @param size Size of rendered string
 * @param depth Depth of object
 * @param error Error status
 */
void internal_cjson_string_size_number(cjson_t *cjson, size_t *size);

/**
 * @brief Get rendering size of given null
 * @param size Size of rendered string
 */
void internal_cjson_string_size_null(size_t *size);

/**
 * @brief Get rendering size of given boolean
 * @param cjson Boolean CJSON element to stringify
 * @param size Size of rendered string
 */
void internal_cjson_string_size_bool(cjson_t *cjson, size_t *size);

/**
 * @brief Get rendering size of given string
 * @param cjson String CJSON element to stringify
 * @param size Size of rendered string
 */
void internal_cjson_string_size_string(cjson_t *cjson, size_t *size);

/**
 * @brief Get rendering size of given CJSON object
 * @param cjson CJSON object to stringify
 * @param size Size of rendered string
 * @param depth Depth of object
 * @param error Error status
 */
void internal_cjson_string_size_object(cjson_t *cjson, size_t *size,
int depth, bool *error);

/**
 * @brief Get rendering size of given CJSON element
 * @param cjson CJSON element to stringify
 * @param size Size of rendered string
 * @param depth Depth of object
 * @param error Error status
 */
void internal_cjson_string_size(cjson_t *cjson, size_t *size,
int depth, bool *error);

/**
 * @brief Add tabs in total size
 * @param depth Depth of object
 * @param size Size of rendered string
 */
void internal_cjson_string_size_add_tabs(int depth, size_t *size);

/**
 * @brief Stringify given CJSON element
 * @param cjson CJSON element to stringify
 * @param json JSON rendering string
 * @param depth Depth of rendering
 * @param error Error status
 */
void internal_cjson_stringify(cjson_t *cjson, internal_cjson_string_t *json,
int depth, bool *error);

/**
 * @brief Add tabs depending on depth
 * @param json JSON rendering string
 * @param depth Depth of rendering
 */
void internal_cjson_stringify_add_tabs(internal_cjson_string_t *json,
int depth);

/**
 * @brief Stringify given CJSON boolean value
 * @param cjson CJSON boolean element
 * @param json JSON rendering string
 */
void internal_cjson_stringify_bool(cjson_t *cjson,
internal_cjson_string_t *json);

/**
 * @brief Stringify given CJSON null value
 * @param json JSON rendering string
 */
void internal_cjson_stringify_null(internal_cjson_string_t *json);

/**
 * @brief Stringify given CJSON object
 * @param cjson CJSON element to stringify
 * @param json JSON rendering string
 * @param depth Depth of rendering
 * @param error Error status
 */
void internal_cjson_stringify_object(cjson_t *cjson,
internal_cjson_string_t *json, int depth, bool *error);

/**
 * @brief Stringify given CJSON array
 * @param cjson CJSON array to stringify
 * @param json JSON rendering string
 * @param depth Depth of rendering
 * @param error Error status
 */
void internal_cjson_stringify_array(cjson_t *cjson,
internal_cjson_string_t *json, int depth, bool *error);

/**
 * @brief Stringify given CJSON string
 * @param cjson CJSON string to stringify
 * @param json JSON rendering string
 */
void internal_cjson_stringify_string(cjson_t *cjson,
internal_cjson_string_t *json);

/**
 * @brief Stringify given CJSON string
 * @param cjson CJSON string to stringify
 * @param json JSON rendering string
 */
void internal_cjson_stringify_number(cjson_t *cjson,
internal_cjson_string_t *json);

#endif /* !CJSON_INTERNAL_STRINGIFY_H_ */
