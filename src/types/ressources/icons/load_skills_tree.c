/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "app/loading/loading.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"

static void icon_load_data_credit(icons_competences_t *tree, cjson_t *configs)
{
    char *one_cred = cjson_get_prop_string_unsafe(configs, "one_credits");
    char *three_cred = cjson_get_prop_string_unsafe(configs, "three_credits");
    char *five_cred = cjson_get_prop_string_unsafe(configs, "five_credits");

    tree->one_credit = sfTexture_createFromFile(one_cred, NULL);
    tree->three_credit = sfTexture_createFromFile(three_cred, NULL);
    tree->five_credit = sfTexture_createFromFile(five_cred, NULL);
    free(one_cred);
    free(three_cred);
    free(five_cred);
}

static void first_competence(icons_competences_t *tree, cjson_t *configs)
{
    char *left_lock = cjson_get_prop_string_unsafe(configs, "script_bash_lock");
    char *left_unlock = cjson_get_prop_string_unsafe(configs, "script_bash_unlock");
    char *right_lock = cjson_get_prop_string_unsafe(configs, "flipper_lock");
    char *right_unlock =
    cjson_get_prop_string_unsafe(configs, "flipper_unlock");

    tree->script_bash_lock = sfTexture_createFromFile(left_lock, NULL);
    tree->script_bash_unlock = sfTexture_createFromFile(left_unlock, NULL);
    tree->flipper_lock = sfTexture_createFromFile(right_lock, NULL);
    tree->flipper_unlock = sfTexture_createFromFile(right_unlock, NULL);
    free(left_lock);
    free(left_unlock);
    free(right_lock);
    free(right_unlock);
    icon_load_data_credit(tree, configs);
}

void icons_load_data_competence(icons_competences_t *tree, cjson_t *configs)
{
    char *top_lock = cjson_get_prop_string_unsafe(configs, "brute_force_lock");
    char *top_unlock = cjson_get_prop_string_unsafe(configs, "brute_force_unlock");
    char *middle_lock = cjson_get_prop_string_unsafe(configs, "go_buster_lock");
    char *middle_unlock = cjson_get_prop_string_unsafe(configs, "go_buster_unlock");

    tree->brute_force_lock = sfTexture_createFromFile(top_lock, NULL);
    tree->brute_force_unlock = sfTexture_createFromFile(top_unlock, NULL);
    tree->go_buster_lock = sfTexture_createFromFile(middle_lock, NULL);
    tree->go_buster_unlock = sfTexture_createFromFile(middle_unlock, NULL);
    free(top_lock);
    free(top_unlock);
    free(middle_lock);
    free(middle_unlock);
    first_competence(tree, configs);
}
