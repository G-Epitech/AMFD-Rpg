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

    #define ZOOM_TIME 10
    #define ZOOM_RATIO 100
    #define SHAKE_TIME 5
    #define SHAKE_TARGET 500
    #define FLOATING_TEXT_TIME 10
    #define FLOATING_TEXT_TARGET 1200
    #define NOTIF_TIME 10
    #define NOTIF_TARGET_SLIDE 700
    #define NOTIF_TARGET_AFK 2300
    #define NOTIF_POSITION_INIT ((sfVector2f) {1900, 728})
    #define NOTIF_POSITION_TARGET ((sfVector2f) {1369, 728})
    #define FADE_TIME 10
    #define FADE_RATIO 2200

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

typedef struct s_animation_event_fade {
    sfInt32 last_time;
    int total;
    sfColor color;
} animation_event_fade_t;

typedef struct s_animation_event_shake_attack {
    attack_t *attack;
    sfVector2f origin;
    sfInt32 last_time;
    sfInt32 total_time;
    sfInt32 target_time;
    int target_offset;
    int total_offset;
} animation_event_shake_attack_t;

typedef struct s_animation_event_floating_text {
    sfColor color;
    sfVector2f position;
    int size;
    sfInt32 last_time;
    sfInt32 total_time;
    char *content;
} animation_event_floating_text_t;

typedef struct s_animation_event_notif {
    char *title;
    char *description;
    sfTexture *icon;
    sfInt32 last_time;
    sfInt32 total_time;
    sfVector2f position;
} animation_event_notif_t;

typedef union u_animation_event_data {
    animation_event_npc_t *npc;
    animation_event_zoom_t *zoom;
    animation_event_fade_t *fade;
    animation_event_notif_t *notif;
    animation_event_player_t *player;
    animation_event_shake_attack_t *shake_attack;
    animation_event_floating_text_t *floating_text;
} animation_event_data_t;

typedef enum e_animation_event_type {
    AE_NULL = 0,
    AE_ZOOM,
    AE_FADE,
    AE_MOVE_NPC,
    AE_MOVE_PLAYER,
    AE_SHAKE_ATTACK,
    AE_FLOATING_TEXT,
    AE_NOTIF
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
