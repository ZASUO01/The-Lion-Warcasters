//
// Created by pedro-souza on 07/10/2025.
//
#include "Client.h"
#include "NetLogger.h"
#include "Socket.h"
#include  "Addrresses.h"
#include "Defs.h"
#include  "NetUtils.h"

void init_net_client(NetClient *client) {
    client->state = CLIENT_CLOSED;
    client->socket = create_socket_v4();
    client->nonce = generate_nonce();

    LOG_MSG(LOG_INFO, "client struct initialized");
}

int add_server_addr(NetClient *client, const char *ip) {
    if (client->state == CLIENT_CLOSED) {
        struct sockaddr_in addr_v4;

        if (parse_addr_v4(&addr_v4, ip, APP_PORT) != 0) {
            return -1;
        }

        client->server_addr_v4 = addr_v4;
        client->state = CLIENT_READY;

        LOG_MSG(LOG_INFO, "server addr added");
        return 0;
    }

    return -1;
}

int close_client(NetClient * client) {
    if (close_socket(client->socket) != 0) {
        sys_log_exit("close socket failure");
    }

    client->state = CLIENT_CLOSED;
    LOG_MSG(LOG_INFO, "client closed");
}