//
// Created by pedro-souza on 08/11/2025.
//

#include "Addresses.h"

void Addresses::initAddrAnyV4(sockaddr_in *addr4, const unsigned int port) {
    addr4->sin_family = AF_INET;
    addr4->sin_addr.s_addr = INADDR_ANY;
    addr4->sin_port = htons(port);
}
