/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** types
*/

#ifndef ANIMATIONS_TYPES_H_
    #define ANIMATIONS_TYPES_H_

    #include <SFML/Graphics.h>
    #include "types/npc/types.h"
    #include "types/players/types.h"

    #define PLAYER_IN_ANIM(animation) (animation->events->len > 0)

typedef struct s_list list_t;

typedef struct s_animation_event_player {
    player_t *player;
    sfVector2f target;
    sfInt64 last_time;
    float speed;
} animation_event_player_t;

typedef struct s_animation_event_npc {
    npc_t *npc;
    sfVector2f target;
    sfInt64 last_time;
    float speed;
} animation_event_npc_t;

typedef union u_animation_event_data {
    animation_event_npc_t *npc;
    animation_event_player_t *player;
} animation_event_data_t;

typedef enum e_animation_event_type {
    AE_NULL = 0,
    AE_ZOOM,
    AE_MOVE_NPC,
    AE_MOVE_PLAYER,
    AE_FADE
} animation_event_type_t;

typedef struct s_animation_event {
    animation_event_type_t type;
    animation_event_data_t data;
} animation_event_t;

typedef struct s_animations {
    list_t *events;
    list_t *map;
} animations_t;

#endif /* !ANIMATIONS_TYPES_H_ */
