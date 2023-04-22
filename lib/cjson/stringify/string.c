/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** null
*/

#include "types.h"
#include "internal/defs.h"
#include "internal/utils.h"
#include "internal/error.h"
#include "internal/stringify.h"

static char get_special_escape_char(char special)
{
    size_t index = 0;

    for (size_t k = 0; k < CJSON_SPECIAL_CHARS_LEN; k++) {
        if (CJSON_SPECIAL_CHARS_VALUES[k] == special) {
            index = k;
            break;
        }
    }
    return CJSON_SPECIAL_CHARS[index];
}

static void copy_string(char *string,
internal_cjson_string_t *json)
{
    size_t i = 0;

    while (string[i] != '\0') {
        if (CJSON_INTERNAL_IS_SPECIAL(string[i])) {
            json->content[json->i++] = '\\';
            json->content[json->i++] = get_special_escape_char(string[i]);
        } else {
            json->content[json->i++] = string[i];
        }
        i += 1;
    }
}

void internal_cjson_stringify_string(cjson_t *cjson,
internal_cjson_string_t *json)
{
    char *string = cjson->value.v_string;
    int len = internal_cjson_strlen(string);

    json->content[json->i++] = '"';
    copy_string(string, json);
    json->content[json->i++] = '"';
}
