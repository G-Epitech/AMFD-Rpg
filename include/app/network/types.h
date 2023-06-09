/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** types
*/

#ifndef NETWORK_TYPES_H_
    #define NETWORK_TYPES_H_

    #include <SFML/Graphics.h>
    #include <SFML/Network.h>

typedef struct s_network {
    sfTcpListener *listener;
    sfTcpSocket *socket;
    sfVector2f position;
    int state;
} network_t;

#endif /* !NETWORK_TYPES_H_ */
