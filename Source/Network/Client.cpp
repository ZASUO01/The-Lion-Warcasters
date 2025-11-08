//
// Created by pedro-souza on 08/11/2025.
//

#include "Client.h"

#include "Addresses.h"
#include "Defs.h"
#include "Logger.h"
#include "Socket.h"

Client::Client()
:state(ClientState::CLIENT_DOWN)
,sockFd(-1)
,serverAddrV4{}
{}

void Client::Init(const char *serverIp) {
    if (state != ClientState::CLIENT_DOWN) {
        return;
    }

    sockFd = SocketUtils::createSocketV4();

    if (!Addresses::parseAddrV4(&serverAddrV4, serverIp, APP_PORT)) {
        Shutdown();
        return;
    }

    state = ClientState::CLIENT_READY;
}

void Client::Shutdown()  {
    if (close_socket(sockFd) != 0) {
        Logger::sysLogExit("close socket");
    }

    state = ClientState::CLIENT_DOWN;
}

