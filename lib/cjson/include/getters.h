/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** getters
*/

#ifndef CJSON_GETTERS_H_
    #define CJSON_GETTERS_H_

    #include "types.h"

/**
 * @brief Get array value of given CJSON element
 * @param cjson CJSON element on which get int value
 * @param value Pointer to cjson_array_t into which store extracted value
 * @return Value retrieval success status
 */
bool cjson_get_array(cjson_t *cjson, cjson_array_t **value);

/**
 * @brief Get int value of given CJSON element
 * @param cjson CJSON element on which get int value
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is array. This function could return NULL if element is not a array.
 * In this case you will not be able to do the difference between value NULL
 * contained in given CJSON element or if is an error.
 * To prevent error use cjson_get_array instead.
 */
cjson_array_t *cjson_get_array_unsafe(cjson_t *cjson);

/**
 * @brief Get int value of given CJSON element
 * @param cjson CJSON element on which get int value
 * @param value Pointer to int into which store extracted value
 * @return Value retrieval success status
 * @note If number is float, it will be truncate to int.
 */
bool cjson_get_int(cjson_t *cjson, int *value);

/**
 * @brief Get int value of given CJSON element
 * @param cjson CJSON element on which get int value
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is number. This function could return 0 if element is not a number.
 * In this case you will not be able to do the difference between value 0
 * contained in given CJSON element or if is an error.
 * To prevent error use cjson_get_int instead.
 * @note If number is float, it will be truncate to int.
 */
int cjson_get_int_unsafe(cjson_t *cjson);

/**
 * @brief Get float value of given CJSON element
 * @param cjson CJSON element on which get float value
 * @param value Pointer to float into which store extracted value
 * @return Value retrieval success status
 */
bool cjson_get_float(cjson_t *cjson, float *value);

/**
 * @brief Get float value of given CJSON element
 * @param cjson CJSON element on which get float value
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is number. This function could return 0 if element is not a number.
 * In this case you will not be able to do the difference between value 0
 * contained in given CJSON element or if is an error.
 * To prevent error use cjson_get_float instead.
 */
float cjson_get_float_unsafe(cjson_t *cjson);

/**
 * @brief Get bool value of given CJSON element
 * @param cjson CJSON element on which get bool value
 * @param value Pointer to bool into which store extracted value
 * @return Value retrieval success status
 */
bool cjson_get_bool(cjson_t *cjson, bool *value);

/**
 * @brief Get bool value of given CJSON element
 * @param cjson CJSON element on which get bool value
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is bool. This function could return false if element is not a bool.
 * In this case you will not be able to do the difference between value false
 * contained in given CJSON element or if is an error.
 * To prevent error use cjson_get_bool instead.
 */
bool cjson_get_bool_unsafe(cjson_t *cjson);

/**
 * @brief Get string value of given CJSON element
 * @param cjson CJSON element on which get string value
 * @param value Pointer to string into which store extracted value
 * @return Value retrieval success status
 */
bool cjson_get_string(cjson_t *cjson, char **value);

/**
 * @brief Get string value of given CJSON element
 * @param cjson CJSON element on which get string value
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is string. This function could return NULL if element is not a string.
 * In this case you will not be able to do the difference between value NULL
 * contained in given CJSON element or if is an error.
 * To prevent error use cjson_get_string instead.
 */
char *cjson_get_string_unsafe(cjson_t *cjson);

#endif /* !CJSON_GETTERS_H_ */
