//
// Created by pedro-souza on 21/10/2025.
//

#ifndef ADDRESSES_H
#define ADDRESSES_H

#include "Platforms.h"
#include <cstdint>

namespace Addresses {
    bool parseAddrV4(struct sockaddr_in *addr, const char *addr_str, uint16_t port);
};


#endif //ADDRESSES_H