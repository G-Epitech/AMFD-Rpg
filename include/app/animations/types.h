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
    #define ZOOM_TIME 10
    #define ZOOM_RATIO 100
    #define SHAKE_TIME 5
    #define SHAKE_TARGET 500

typedef struct s_list list_t;
typedef struct s_attack attack_t;

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

typedef struct s_animation_event_zoom {
    sfView *view;
    float zoom;
    sfInt32 last_time;
    float speed;
    int total;
} animation_event_zoom_t;

typedef struct s_animation_event_shake_attack {
    attack_t *attack;
    sfVector2f origin;
    sfInt32 last_time;
    sfInt32 total_time;
    sfInt32 target_time;
    int target_offset;
    int total_offset;
} animation_event_shake_attack_t;

typedef union u_animation_event_data {
    animation_event_zoom_t *zoom;
    animation_event_npc_t *npc;
    animation_event_player_t *player;
    animation_event_shake_attack_t *shake_attack;
} animation_event_data_t;

typedef enum e_animation_event_type {
    AE_NULL = 0,
    AE_ZOOM,
    AE_FADE,
    AE_MOVE_NPC,
    AE_MOVE_PLAYER,
    AE_SHAKE_ATTACK
} animation_event_type_t;

typedef struct s_animation_event {
    animation_event_type_t type;
    animation_event_data_t data;
} animation_event_t;

typedef struct s_animations {
    list_t *events;
    list_t *map;
    sfClock *clock;
} animations_t;

#endif /* !ANIMATIONS_TYPES_H_ */
