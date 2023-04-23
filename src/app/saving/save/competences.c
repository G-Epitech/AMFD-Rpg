/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include <sys/stat.h>
#include "app/app.h"
#include "types/list/types.h"
#include "cjson/include/cjson.h"

static void append_competence(competences_node_t *competence,
cjson_array_t *array)
{
    cjson_t *export = cjson_new(NULL);

    if (!export)
        return;
    cjson_set_prop(export, "id",
    CJSON_NUMBER(competence->id), CJSON_NUMBER_T);
    cjson_set_prop(export, "unlock", CJSON(competence->unlock), CJSON_BOOL_T);
    cjson_array_append(array, export);
}

static void fill_competences(list_t *competences, cjson_array_t *array)
{
    node_t *node = competences ? competences->first : NULL;

    while (node) {
        append_competence(node->data.competence, array);
        node = node->next;
    }
}

void save_export_competences(list_t *competences, cjson_t *export)
{
    cjson_array_t *array = cjson_array_new();

    if (!array)
        return;
    fill_competences(competences, array);
    cjson_set_prop(export, "competences", CJSON(array), CJSON_ARRAY_T);
}
