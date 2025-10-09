//
// Created by pedro-souza on 08/10/2025.
//

#ifndef PLATFORMS_H
#define PLATFORMS_H

#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOWS 1
#elif defined(__linux__)
    #define PLATFORM_LINUX 1
#endif


#ifdef PLATFORM_WINDOWS
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif

    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <windows.h>

    #define close_socket closesocket

    #pragma comment(lib, "ws2_32.lib")

#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>

    #define close_socket close
#endif

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include  <errno.h>
#include  <string.h>

int platform_networking_init();
void platform_networking_cleanup();

#endif PLATFORMS_H