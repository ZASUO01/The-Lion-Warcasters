//
// Created by pedro-souza on 06/11/2025.
//

#ifndef NETUTILS_H
#define NETUTILS_H

#include <cstdint>
#include <cstdlib>

namespace  NetUtils {
    uint16_t getNetChecksum(const void *data, size_t dataSize);
};


#endif //NETUTILS_H