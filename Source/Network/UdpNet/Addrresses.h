//
// Created by pedro-souza on 08/10/2025.
//

#ifndef ADDRRESSES_H
#define ADDRRESSES_H

#include <arpa/inet.h>
#include <stdint.h>

int parse_addr_v4(struct sockaddr_in *addr, const char *addr_str, uint16_t port);

#endif ADDRRESSES_H