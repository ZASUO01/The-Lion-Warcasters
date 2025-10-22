//
// Created by pedro-souza on 17/10/2025.
//

#include "Socket.h"
#include "Platforms.h"
#include "NetLogger.h"

int SocketUtils::createUDPSocketV4() {
    int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (fd < 0) {
        NetLogger::sysLogExit("socket creation failure");
    }

    return fd;
}
