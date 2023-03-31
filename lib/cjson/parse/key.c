/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** key
*/

#include <stdlib.h>
#include "internal/error.h"
#include "internal/utils.h"
#include "internal/parsing.h"

static int get_key_len(char *json, int i, bool *error)
{
    int len = 0;

    while (json[i + len] != '"' && json[i + len] != '\0') {
        len++;
    }
    if (json[i + len] == '\0')
        internal_cjson_error("end of file reached without found '\"'", error);
    return len;
}

static void get_key_content(char *json, int len, char **key, bool *error)
{
    *key = internal_cjson_strndup(json, len);
    if (!key)
        return internal_cjson_error("unable to allocate key.", error);
}

char *internal_cjson_parse_key(char *json, int *i, bool *error)
{
    char *key = NULL;
    int len = 0;

    internal_cjson_skip_blank(json, i);
    if (json[*i] != '"') {
        internal_cjson_error(
            "unable to find expected '\"' on object property key",
            error
        );
        return key;
    }
    *i += 1;
    len = get_key_len(json, *i, error);
    if ((*error))
        return key;
    get_key_content(json + (*i), len, &key, error);
    *i += len + 1;
    return key;
}
