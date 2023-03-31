/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** array
*/

#ifndef CJSON_ARRAY_H_
    #define CJSON_ARRAY_H_

    #include "types.h"

/**
 * @brief Create a new CJSON array
 * @return Created array or NULL if failed
 */
cjson_array_t *cjson_array_new(void);

/**
 * @brief Free given CJSON array
 * @param array Array to free
 */
void cjson_array_free(cjson_array_t *array);

/**
 * @brief Get ith element in given array
 * @param array Array in which get element
 * @param index Index of element to get
 * @return Expected element or NULL on failure
 */
cjson_t *cjson_array_get(cjson_array_t *array, size_t index);

/**
 * @brief Append given value in given array
 * @param array Array in which append value
 * @param element Element to append in given array
 */
void cjson_array_append(cjson_array_t *array, cjson_t *element);

/**
 * @brief Remove given element from given array
 * @param array Array in which remove element
 * @param element Element to remove in given array
 */
void cjson_array_remove(cjson_array_t *array, cjson_t *element);

/**
 * @brief Remove given element from given array and free it
 * @param array Array in which remove element
 * @param element Element to remove in given array
 * @warning This function destroy given element by freeing it.
 * Don't use this function if you want to keep accessible the element.
 * In this case use 'cjson_array_remove' instead.
 */
void cjson_array_delete(cjson_array_t *array, cjson_t *element);

/**
 * @brief Convert given CJSON array to an array of strings
 * @param cjson CJSON element
 * @return Converted array or NULL on failure
 * @warning All array elements needs to be string otherwise operation
 * will fail and return NULL.
 * @note Created array is NULL terminated.
 */
char **cjson_array_to_string_array(cjson_array_t *cjson);

/**
 * @brief Free given array of strings
 * @param array Array to free
 * @warning Given array needs to be NULL terminated otherwise function
 * could fail.
 */
void cjson_array_free_string_array(char **array);

/**
 * @brief Convert given CJSON array to an array of int
 * @param cjson CJSON element
 * @param size Pointer to variable in which store size of created array
 * @return Converted array or NULL on failure
 * @warning All array elements needs to be number otherwise operation
 * will fail and return NULL.
 * @warning If all given number are not integers but floats there will
 * be converted to there more close int value.
 */
int *cjson_array_to_int_array(cjson_array_t *cjson, size_t *size);

/**
 * @brief Convert given CJSON array to an array of float
 * @param cjson CJSON element
 * @param size Pointer to variable in which store size of created array
 * @return Converted array or NULL on failure
 * @warning All array elements needs to be number otherwise operation
 * will fail and return NULL.
 */
float *cjson_array_to_float_array(cjson_array_t *cjson, size_t *size);

/**
 * @brief Convert given CJSON array to an array of bool
 * @param cjson CJSON element
 * @param size Pointer to variable in which store size of created array
 * @return Converted array or NULL on failure
 * @warning All array elements needs to be bool otherwise operation
 * will fail and return NULL.
 */
bool *cjson_array_to_bool_array(cjson_array_t *cjson, size_t *size);

/**
 * @brief Create a new CJSON array from given bool array
 * @param array Array of bool to convert
 * @param size Size of given array
 * @return Created CJSON array or NULL on failure
 */
cjson_array_t *cjson_array_from_bool_array(bool *array, size_t size);

/**
 * @brief Create a new CJSON array from given float array
 * @param array Array of float to convert
 * @param size Size of given array
 * @return Created CJSON array or NULL on failure
 */
cjson_array_t *cjson_array_from_float_array(float *array, size_t size);

/**
 * @brief Create a new CJSON array from given int array
 * @param array Array of int to convert
 * @param size Size of given array
 * @return Created CJSON array or NULL on failure
 */
cjson_array_t *cjson_array_from_int_array(int *array, size_t size);

/**
 * @brief Create a new CJSON array from given string array
 * @param array Array of string to convert
 * @return Created CJSON array or NULL on failure
 * @warning Given array needs to be NULL terminated otherwise function
 * will fail.
 */
cjson_array_t *cjson_array_from_string_array(char **array);

#endif /* !CJSON_ARRAY_H_ */
