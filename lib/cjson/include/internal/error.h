/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** error
*/

#ifndef CJSON_INTERNAL_ERROR_H_
    #define CJSON_INTERNAL_ERROR_H_

    #include <stdbool.h>
    #include <stdio.h>

/**
 * @brief Display error on stderr
 * @param message Message to display
 * @param error Error status
 */
void internal_cjson_error(const char *message, bool *error);

#endif /* !CJSON_INTERNAL_ERROR_H_ */
