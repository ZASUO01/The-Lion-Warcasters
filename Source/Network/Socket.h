//
// Created by pedro-souza on 07/11/2025.
//

#ifndef SOCKET_H
#define SOCKET_H

#include "Platforms.h"
#include "Packet.h"


namespace SocketUtils {
    int createSocketV4();
    void bindSocketToAnyV4(int sock);
    bool socketReadyToReceive(int sock, int ms);
    bool sendPacketToV4(int sock, const char *pk, size_t pkSize, sockaddr_in addr4);
    bool receivePacketFromV4(int sock, Packet *pk, sockaddr_in addr4);
};


#endif //SOCKET_H