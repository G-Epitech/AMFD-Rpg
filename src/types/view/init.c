/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init view of the applicatio
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/view/types.h"

sfView *view_init(void)
{
    sfView *view = sfView_create();

    if (!view)
        return NULL;
    sfView_setSize(view, VIEW_RESOLUTION);
    sfView_setCenter(view, VIEW_POSITION);
    sfView_zoom(view, VIEW_ZOOM);
    return view;
}
