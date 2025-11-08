//
// Created by pedro-souza on 08/11/2025.
//

#ifndef CLIENT_H
#define CLIENT_H

#include "Platforms.h"

enum class ClientState {
    CLIENT_DOWN,
    CLIENT_READY,
};

class Client {
public:
    Client();
    void Init(const char *serverIp);
    void Shutdown();

    [[nodiscard]] ClientState GetClientState() const { return state; }
private:
    ClientState state;
    int sockFd;
    sockaddr_in serverAddrV4;
};


#endif //CLIENT_H