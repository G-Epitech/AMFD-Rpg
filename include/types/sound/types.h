/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Contains the types for the soundboard
*/

#ifndef SOUND_TYPES_H_
    #define SOUND_TYPES_H_

    #include <SFML/Audio.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Vector3.h>
    #include <stdbool.h>
    
    #define SOUND_CONFIG "configs/sounds.json"

typedef struct s_list list_t;

/**
 * @brief Structure for a sound,
 * contains all useful parameters for sound playing
*/
typedef struct sound_s {
    char *title;
    sfSoundBuffer *buffer;
    float volume;
    bool loop;
    sfSoundStatus status;
    sfSound *sound;
} sound_t;

#endif /* !SOUND_TYPES_H_ */
