/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** cjson
*/

#ifndef CJSON_H_
    #define CJSON_H_

    #include "types.h"
    #include "display.h"
    #include "parsing.h"
    #include "getters.h"
    #include "stringify.h"
    #include "types/array.h"
    #include "types/object.h"

    #define CJSON(v) ((cjson_value_t) v)
    #define CJSON_NUMBER(v) CJSON((float) v)
    #define CJSON_STRING(v) CJSON((char *) v)
    #define CJSON_OBJECT(v) CJSON((cjson_t *) v)
    #define CJSON_ARRAY(v) CJSON((cjson_array_t *) v)
    #define CJSON_BOOL(v) CJSON((bool) v)

#endif /* !CJSON_H_ */
