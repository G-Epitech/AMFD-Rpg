/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** types
*/

#ifndef CJSON_TYPES_H_
    #define CJSON_TYPES_H_
    #include <sys/types.h>
    #include <stdbool.h>

typedef int cjson_null_t;
typedef struct s_cjson cjson_t;

typedef struct s_internal_cjson_number {
    bool negative;
    bool dot;
    long whole;
    long decimal;
    long divider;
} internal_cjson_number_t;

typedef struct s_internal_cjson_string {
    char *content;
    size_t i;
} internal_cjson_string_t;

typedef struct s_cjson_array {
    cjson_t *first;
    cjson_t *last;
    size_t len;
} cjson_array_t;

typedef union s_cjson_value {
    cjson_t *v_object;
    cjson_array_t *v_array;
    char *v_string;
    float v_number;
    bool v_bool;
    cjson_null_t v_null;
} cjson_value_t;

typedef enum s_cjson_type {
    CJSON_OBJECT_T,
    CJSON_ARRAY_T,
    CJSON_STRING_T,
    CJSON_NUMBER_T,
    CJSON_BOOL_T,
    CJSON_NULL_T
} cjson_type_t;

typedef struct s_cjson_file {
    char *content;
    int fd;
} cjson_file_t;

typedef struct s_cjson {
    char *key;
    cjson_value_t value;
    cjson_type_t type;
    cjson_t *prev;
    cjson_t *next;
} cjson_t;

    #define CJSON_IS_OBJECT(o) (o->type == CJSON_OBJECT_T)
    #define CJSON_IS_ARRAY(o) (o->type == CJSON_ARRAY_T)
    #define CJSON_IS_STRING(o) (o->type == CJSON_STRING_T)
    #define CJSON_IS_NUMBER(o) (o->type == CJSON_NUMBER_T)
    #define CJSON_IS_BOOL(o) (o->type == CJSON_BOOL_T)
    #define CJSON_IS_NULL(o) (o->type == CJSON_NULL_T)
    #define CJSON_IS_PRIMARY(o) (!CJSON_IS_ARRAY(o) && !CJSON_IS_OBJECT(o))

    #define CJSON_NULL ((cjson_value_t) 0)

#endif /* !CJSON_TYPES_H_ */
