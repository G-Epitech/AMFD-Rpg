/*
** EPITECH PROJECT, 2023
** test.c
** File description:
** Test file
*/

#include "my/include/my.h"
#include "types/renderer/types.h"
#include "app/types.h"

int test(renderer_t *renderer, app_t *app)
{
    (void) renderer;
    (void) app;
    my_putstr("Test event function");
    return 1;
}
