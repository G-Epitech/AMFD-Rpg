/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** object
*/

#ifndef CJSON_OBJECT_H_
    #define CJSON_OBJECT_H_

    #include "../types.h"

/**
 * @brief Create a new CJSON element, object as default
 * @param key Object key
 * @return Created element
 * @note You can change type of element with cjson_set_value
 */
cjson_t *cjson_new(char *key);

/**
 * @brief Free given CJSON object
 * @param cjson CJSON object to free
 */
void cjson_free(cjson_t *cjson);

/**
 * @brief Free value of given CJSON element without
 * free its key and alloced element
 * @param cjson CJSON element of which free value
 */
void cjson_free_value(cjson_t *cjson);

/**
 * @brief Get property in given object
 * @param object Object in which get value
 * @param key Key of property
 * @return Property if found, NULL if not found
 */
cjson_t *cjson_get_prop(cjson_t *object, char *key);

/**
 * @brief Get value of property as array in given object
 * @param object Object in which get value
 * @param key Key of property
 * @param value Pointer to array into which store extracted value
 * @return Value retrieval success status
 */
bool cjson_get_prop_array(cjson_t *object, char *key, cjson_array_t **value);

/**
 * @brief Get value of property as array in given object
 * @param object Object in which get value
 * @param key Key of property
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is number and property exsits. This function could return 0
 * if element is not a number or not found. In this case you will not
 * be able to do the difference between value 0 contained in given CJSON
 * element or if is an error. To prevent error use cjson_get_array instead.
 * @note If number is array, it will be truncate to array.
 */
cjson_array_t *cjson_get_prop_array_unsafe(cjson_t *object, char *key);

/**
 * @brief Get value of property as int in given object
 * @param object Object in which get value
 * @param key Key of property
 * @param value Pointer to int into which store extracted value
 * @return Value retrieval success status
 * @note If number is float, it will be truncate to int.
 */
bool cjson_get_prop_int(cjson_t *object, char *key, int *value);

/**
 * @brief Get value of property as int in given object
 * @param object Object in which get value
 * @param key Key of property
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is number and property exsits. This function could return 0
 * if element is not a number or not found. In this case you will not
 * be able to do the difference between value 0 contained in given CJSON
 * element or if is an error. To prevent error use cjson_get_int instead.
 * @note If number is int, it will be truncate to int.
 */
int cjson_get_prop_int_unsafe(cjson_t *object, char *key);

/**
 * @brief Get value of property as float in given object
 * @param object Object in which get value
 * @param key Key of property
 * @param value Pointer to float into which store extracted value
 * @return Value retrieval success status
 */
bool cjson_get_prop_float(cjson_t *object, char *key, float *value);

/**
 * @brief Get value of property as float in given object
 * @param object Object in which get value
 * @param key Key of property
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is number and property exsits. This function could return 0
 * if element is not a number or not found. In this case you will not
 * be able to do the difference between value 0 contained in given CJSON
 * element or if is an error. To prevent error use cjson_get_float instead.
 * @note If number is float, it will be truncate to float.
 */
float cjson_get_prop_float_unsafe(cjson_t *object, char *key);

/**
 * @brief Get value of property as bool in given object
 * @param object Object in which get value
 * @param key Key of property
 * @param value Pointer to bool into which store extracted value
 * @return Value retrieval success status
 */
bool cjson_get_prop_bool(cjson_t *object, char *key, bool *value);

/**
 * @brief Get value of property as bool in given object
 * @param object Object in which get value
 * @param key Key of property
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is boolean and property exsits. This function could return false
 * if element is not a boolean or not found. In this case you will not
 * be able to do the difference between value false contained in given CJSON
 * element or if is an error. To prevent error use cjson_get_bool instead.
 */
bool cjson_get_prop_bool_unsafe(cjson_t *object, char *key);

/**
 * @brief Get value of property as string in given object
 * @param object Object in which get value
 * @param key Key of property
 * @param value Pointer to string into which store extracted value
 * @return Value retrieval success status
 */
bool cjson_get_prop_string(cjson_t *object, char *key, char **value);

/**
 * @brief Get value of property as string in given object
 * @param object Object in which get value
 * @param key Key of property
 * @return Extracted value
 * @warning Doesn't use this function if your not sure that CJSON element
 * type is string and property exsits. This function could return NULL
 * if element is not a string or not found. In this case you will not
 * be able to do the difference between value NULL contained in given CJSON
 * element or if is an error. To prevent error use cjson_get_string instead.
 */
char *cjson_get_prop_string_unsafe(cjson_t *object, char *key);

/**
 * @brief Set property in given object
 * @param object Object in which set value
 * @param key Key of property
 * @param value Value to set to property
 * @param type Type of value to add in object
 * @return 0 on success and -1 on failed
 * @warning If given key already exists in object, this function will remove
 * it and replace by given value.
 * @note To pass a value to value parameter you can use CJSON defined macro.
 * It will cast it automatically to cjson_value_t type.
 */
int cjson_set_prop(cjson_t *object, char *key, cjson_value_t value,
cjson_type_t type);

/**
 * @brief Unset property in given object
 * @param object Object in which unset property
 * @param key Key of property
 */
void cjson_unset_prop(cjson_t *object, char *key);

/**
 * @brief Set key of given CJSON element
 * @param cjson CJSON element of which set key
 * @param key Key to set to given element
 * @return 0 on success and -1 on failed
 */
int cjson_set_key(cjson_t *cjson, char *key);

/**
 * @brief Set value of given CJSON element
 * @param cjson CJSON element of which set value
 * @param value Value to set to given element
 * @param type Type of given value
 * @return 0 on success and -1 on failed
 */
int cjson_set_value(cjson_t *cjson, cjson_value_t value,
cjson_type_t type);

#endif /* !CJSON_OBJECT_H_ */
