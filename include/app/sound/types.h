/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Contains the types for the soundboard
*/

#ifndef SOUND_TYPES_H_
    #define SOUND_TYPES_H_

    #include <stdbool.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Vector3.h>

    #define SOUND_FX_CONFIG "configs/sound/sound_fx.json"
    #define SOUND_THEME_CONFIG "configs/sound/sound_themes.json"
    #define SOUND_FX app->sound_board->sound_fx
    #define SOUND_THEME app->sound_board->sound_themes

typedef struct s_list list_t;
typedef enum e_app_states app_states_t;

typedef enum e_sound_index {
    WALK,
    CLICK_MENU
} sound_index_t;

/**
 * @brief Structure for a sound,
 * contains all useful parameters for sound playing
*/
typedef struct sound_s {
    char *title;
    sfSoundBuffer *buffer;
    float volume;
    bool loop;
    bool lone;
    sfSoundStatus status;
    sfSound *sound;
} sound_t;

typedef struct sound_theme_s {
    char *title;
    float volume;
    bool loop;
    app_states_t *associated_app_state;
    size_t app_state_size;
    sfSoundStatus status;
    sfMusic *music;
} sound_theme_t;

typedef struct sound_board_s {
    list_t *sound_fx;
    list_t *sound_themes;
} sound_board_t;

#endif /* !SOUND_TYPES_H_ */
