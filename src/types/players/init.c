/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init players list
*/

#include <stdlib.h>
#include "types/players/types.h"
#include "types/list/types.h"
#include "types/list/list.h"

list_t *players_list_init(void)
{
    return list_new();
}
