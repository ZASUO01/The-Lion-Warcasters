//
// Created by pedro-souza on 07/10/2025.
//
#ifndef CLIENT_H
#define CLIENT_H

typedef enum {
    CLIENT_CLOSED = 0,
} NetClientState;

typedef struct {
    NetClientState state;
    int socket;
} NetClient;

void init_net_client(NetClient *client);

#endif //CLIENT_H