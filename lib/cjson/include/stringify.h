/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** stringify
*/

#ifndef CJSON_STRINGIFY_H_
    #define CJSON_STRINGIFY_H_

    #include "types.h"

/**
 * @brief Convert to stirng given CJSON object
 * @param cjson CSJON object to convert
 * @return JSON string
 */
char *cjson_stringify(cjson_t *cjson);

#endif /* !CJSON_STRINGIFY_H_ */
