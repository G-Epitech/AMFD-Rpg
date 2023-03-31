/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** parsing
*/

#ifndef CJSON_PARSING_H_
    #define CJSON_PARSING_H_

    #include "types.h"

/**
 * @brief Parse given JSON content
 * @param json JSON content to parse
 * @return Parsed JSON object or NULL if failed
 */
cjson_t *cjson_parse(char *json);

/**
 * @brief Parse given JSON file
 * @param filepath Path of file to parse
 * @return Parsed JSON object or NULL if failed
 */
cjson_t *cjson_parse_file(char *filepath);

#endif /* !CJSON_PARSING_H_ */
