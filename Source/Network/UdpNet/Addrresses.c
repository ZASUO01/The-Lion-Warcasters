//
// Created by pedro-souza on 08/10/2025.
//

#include "Addrresses.h"

int parse_addr_v4(struct sockaddr_in *addr, const char *addr_str, uint16_t port) {
    struct in_addr addr_v4;
    if (inet_pton(AF_INET, addr_str, &addr_v4) != 1) {
        return -1;
    }

    addr->sin_addr = addr_v4;
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);

    return 0;
}
