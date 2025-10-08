//
// Created by pedro-souza on 07/10/2025.
//
#ifndef CLIENT_H
#define CLIENT_H

#include  <arpa/inet.h>
#include  <stdint.h>

typedef enum {
    CLIENT_CLOSED = 0,
    CLIENT_READY,
} NetClientState;

typedef struct {
    NetClientState state;
    int socket;
    struct sockaddr_in server_addr_v4;

    uint32_t nonce;
} NetClient;

void init_net_client(NetClient *client);
int add_server_addr(NetClient *client, char *ip);

#endif //CLIENT_H