/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** reset
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"

void renderer_objects_reset_sprite(renderer_objects_t *objects)
{
    sfVector2f position = { 0, 0 };
    sfVector2f origin = { 0, 0 };
    sfVector2f scale = { 1, 1 };

    sfSprite_setPosition(objects->sprite, position);
    sfSprite_setOrigin(objects->sprite, origin);
    sfSprite_setScale(objects->sprite, scale);
    sfSprite_setRotation(objects->sprite, 0);
    sfSprite_setColor(objects->sprite, sfWhite);
}

void renderer_objects_reset_text(renderer_objects_t *objects)
{
    sfVector2f position = { 0, 0 };
    sfVector2f origin = { 0, 0 };
    sfVector2f scale = { 1, 1 };

    sfText_setPosition(objects->text, position);
    sfText_setOrigin(objects->text, origin);
    sfText_setScale(objects->text, scale);
    sfText_setRotation(objects->text, 0);
    sfText_setOutlineColor(objects->text, sfTransparent);
}

void renderer_objects_reset_circle(renderer_objects_t *objects)
{
    sfVector2f position = { 0, 0 };
    sfVector2f origin = { 0, 0 };
    sfVector2f scale = { 1, 1 };

    sfCircleShape_setPosition(objects->circle, position);
    sfCircleShape_setOrigin(objects->circle, origin);
    sfCircleShape_setScale(objects->circle, scale);
    sfCircleShape_setRadius(objects->circle, 0);
    sfCircleShape_setOutlineThickness(objects->circle, 0);
}

void renderer_objects_reset_rectangle(renderer_objects_t *objects)
{
    sfVector2f position = { 0, 0 };
    sfVector2f origin = { 0, 0 };
    sfVector2f scale = { 1, 1 };
    sfVector2f size = { 0, 0 };

    sfRectangleShape_setPosition(objects->rectangle, position);
    sfRectangleShape_setOrigin(objects->rectangle, origin);
    sfRectangleShape_setScale(objects->rectangle, scale);
    sfRectangleShape_setSize(objects->rectangle, size);
    sfRectangleShape_setOutlineThickness(objects->rectangle, 0);
}
