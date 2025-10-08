//
// Created by pedro-souza on 07/10/2025.
//
#include "Client.h"
#include "NetLogger.h"

void init_net_client(NetClient *client) {
    client->state = CLIENT_CLOSED;
    client->socket = -1;

    LOG_MSG(LOG_INFO, "client struct initialized");
}
