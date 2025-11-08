//
// Created by pedro-souza on 08/11/2025.
//

#ifndef ADDRESSES_H
#define ADDRESSES_H

#include "Platforms.h"

namespace Addresses {
    void initAddrAnyV4(sockaddr_in *addr4, unsigned int port);
};


#endif //ADDRESSES_H