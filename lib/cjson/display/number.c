/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** null
*/

#include <unistd.h>
#include "internal/defs.h"
#include "internal/display.h"

static void display_whole_part(long whole)
{
    char digit = 0;
    long helper = whole;
    int divider = 1;

    while (helper > 9) {
        divider *= 10;
        helper /= 10;
    }
    while (divider >= 10) {
        digit = '0' + (whole / divider);
        whole = whole % divider;
        divider /= 10;
        write(1, &digit, 1);
    }
    digit = '0' + whole;
    write(1, &digit, 1);
}

static void display_decimal_part(float number)
{
    char digit = 0;

    number -= (int) number;
    write(1, ".", 1);
    for (int i = 0; i < CJSON_ROUNDING_LIMIT; i++) {
        number *= 10;
        digit = number;
        number -= digit;
        digit = '0' + digit;
        write(1, &digit, 1);
    }
}

void internal_cjson_display_number(cjson_t *cjson)
{
    float number = cjson->value.v_number;

    write(1, CJSON_INTERNAL_BLUE, 7);
    if (number < 0) {
            write(1, "-", 1);
        number = -number;
    }
    display_whole_part((int) number);
    if (((int) number) != number)
        display_decimal_part(number);
    write(1, CJSON_INTERNAL_COLOR_RESET, 4);
}
