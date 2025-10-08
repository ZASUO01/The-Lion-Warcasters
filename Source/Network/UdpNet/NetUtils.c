//
// Created by pedro-souza on 08/10/2025.
//

#include "NetUtils.h"

#include <time.h>
#include <stdlib.h>

uint32_t generate_nonce() {
    uint32_t timestamp = (uint32_t)time(NULL);
    uint32_t random_val = rand() & 0xFFFF;
    return (timestamp << 16) | random_val;
}

