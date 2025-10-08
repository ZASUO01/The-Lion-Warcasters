//
// Created by pedro-souza on 08/10/2025.
//

#include "Socket.h"
#include "NetLogger.h"

#include <sys/socket.h>
#include  <arpa/inet.h>

int create_socket_v4() {
    int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (fd < 0) {
        sys_log_exit("socket creation failure");
    }

    return fd;
}