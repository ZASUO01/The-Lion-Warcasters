//
// Created by pedro-souza on 16/10/2025.
//

#ifndef CLIENT_H
#define CLIENT_H

#include "Platforms.h"
#include <cstdint>

enum class NetClientState {
    CLIENT_CLOSED,
    CLIENT_READY,
};

class NetClient {
public:
    NetClient();
    ~NetClient();

    void Init();
    int AddServerAddrV4(const char *ipv4);
    void Close();

    [[nodiscard]] uint32_t GetNonce() const {return nonce;}

private:
    // current client state
    NetClientState state;

    // the socket file descriptor
    int socket;

    // server ipv4 socket address
    struct sockaddr_in server_addr_v4;

    // client identifier in network communication
    uint32_t nonce;
};

#endif //CLIENT_H