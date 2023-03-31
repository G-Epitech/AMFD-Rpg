/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** object
*/

#include <stdlib.h>
#include "cjson.h"
#include "internal/error.h"
#include "internal/utils.h"
#include "internal/parsing.h"

static void check_sign(internal_cjson_number_t *value, char *json,
int *i, bool *error)
{
    internal_cjson_skip_blank(json, i);
    if (json[*i] != '-' && !CJSON_INTERNAL_ISNUM(json[*i]))
        return internal_cjson_error("invalid number found", error);
    if (json[*i] == '-') {
        value->negative = true;
        *i += 1;
    }
}

static void handle_digit(internal_cjson_number_t *value, char *json,
int *i)
{
    int digit = CJSON_INTERNAL_NUM(json[*i]);

    if (value->dot) {
        value->divider *= 10;
        value->decimal *= 10;
        value->decimal += digit;
    } else {
        value->whole *= 10;
        value->whole += digit;
    }
    *i += 1;
}

static void parse_digit(internal_cjson_number_t *value, char *json,
int *i, bool *error)
{
    if (json[*i] == '.' && value->dot)
        return internal_cjson_error("several '.' found in number", error);
    value->dot = json[*i] == '.' ? true : value->dot;
    if (json[*i] == '.') {
        *i += 1;
        return;
    }
    if (!CJSON_INTERNAL_ISNUM(json[*i]))
        return internal_cjson_error("incorrect digit found in number", error);
    handle_digit(value, json, i);
}

static cjson_value_t compose_final_number(internal_cjson_number_t *value,
bool *error)
{
    float number = 0;

    if (!(*error)) {
        number += (float) value->whole;
        number += ((float) value->decimal) / ((float) value->divider);
        if (value->negative)
            number *= -1;
    }
    return CJSON(number);
}

cjson_value_t internal_cjson_parse_number(char *json, int *i, bool *error)
{
    internal_cjson_number_t value = CJSON_INTERNAL_NUM_0;

    check_sign(&value, json, i, error);
    while ((CJSON_INTERNAL_ISNUM(json[*i]) || (json[*i] == '.')) &&
            !(CJSON_INTERNAL_EONUM(json[*i]) || (*error))) {
        parse_digit(&value, json, i, error);
    }
    return compose_final_number(&value, error);
}
