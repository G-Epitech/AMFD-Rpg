/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** null
*/

#include "types.h"
#include "internal/defs.h"
#include "internal/stringify.h"

static void stringify_whole_part(internal_cjson_string_t *json, long whole)
{
    int digit = 0;
    long helper = whole;
    int divider = 1;

    while (helper > 9) {
        divider *= 10;
        helper /= 10;
    }
    while (divider >= 10) {
        digit = whole / divider;
        whole = whole % divider;
        divider /= 10;
        json->content[json->i++] = ('0' + digit);
    }
    json->content[json->i++] = ('0' + whole);
}

static void stringify_decimal_part(internal_cjson_string_t *json,
float number)
{
    int digit = 0;

    number -= (int) number;
    json->content[json->i++] = '.';
    for (int i = 0; i < CJSON_ROUNDING_LIMIT; i++) {
        number *= 10;
        digit = number;
        json->content[json->i++] = ('0' + digit);
        number -= digit;
    }
}

void internal_cjson_stringify_number(cjson_t *cjson,
internal_cjson_string_t *json)
{
    float number = cjson->value.v_number;

    if (number < 0) {
        json->content[json->i++] = '-';
        number = -number;
    }
    stringify_whole_part(json, ((int) number));
    if (((int) number) != number)
        stringify_decimal_part(json, number);
}
