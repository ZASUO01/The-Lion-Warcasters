//
// Created by pedro-souza on 21/10/2025.
//

#include "Addresses.h"

bool Addresses::parseAddrV4(struct sockaddr_in *addr, const char *addr_str, const uint16_t port) {
    struct in_addr addr_v4{};
    if (inet_pton(AF_INET, addr_str, &addr_v4) != 1) {
        return false;
    }

    addr->sin_addr = addr_v4;
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);

    return true;
}
