/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** network
*/

#ifndef NETWORK_H_
    #define NETWORK_H_

    #include "types.h"

typedef struct s_app app_t;
typedef struct s_renderer renderer_t;
typedef struct s_button button_t;

/**
 * @brief Init network structure
 * @return network_t* 
 */
network_t *network_init(void);

/**
 * @brief Host a new game
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Speicific action button
 * @return int Status of the function
 */
int network_connexion_host(renderer_t *renderer, app_t *app, button_t *button);

/**
 * @brief Join a new game
 * @param renderer Renderer structure
 * @param app Application structure
 * @param button Speicific action button
 * @return int Status of the function
 */
int network_connexion_join(renderer_t *renderer, app_t *app, button_t *button);

#endif /* !NETWORK_H_ */
