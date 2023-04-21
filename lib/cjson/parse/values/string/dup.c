/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** len
*/

#include <stdlib.h>
#include <stdbool.h>
#include "internal/defs.h"
#include "internal/utils.h"

static char get_special_char(char *json, char *string, int *i)
{
    size_t index = 0;

    for (size_t k = 0; k < CJSON_SPECIAL_CHARS_LEN; k++) {
        if (CJSON_SPECIAL_CHARS[k] == json[*i + 1]) {
            index = k;
            break;
        }
    }
    *i += 1;
    return CJSON_SPECIAL_CHARS_VALUES[index];
}

char *internal_cjson_parse_string_dup(char *json, int *i, size_t len)
{
    char *string = malloc(len + 1);
    size_t j = 0;

    if (!string)
        return NULL;
    while (json[*i] != '\0' && json[*i] != '"') {
        if (json[*i] == '\\' && CJSON_INTERNAL_IS_ESC_SPECIAL(json[*i + 1]))
            string[j++] = get_special_char(json, string, i);
        else
            string[j++] = json[*i];
        *i += 1;
    }
    string[j] = '\0';
    return string;
}
