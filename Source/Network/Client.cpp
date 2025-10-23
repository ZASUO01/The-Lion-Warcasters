//
// Created by pedro-souza on 16/10/2025.
//

#include "Client.h"

#include "Addresses.h"
#include "NetLogger.h"
#include "NetUtils.h"
#include "Socket.h"
#include "Defs.h"

NetClient::NetClient()
:state(NetClientState::CLIENT_CLOSED)
,socket(-1)
,server_addr_v4({})
,nonce(0)
{}

NetClient::~NetClient() {}

void NetClient::Init() {
    socket = SocketUtils::createUDPSocketV4();
    nonce = NetUtils::generateNonce();

    LOG_MSG(LOG_INFO, "client struct initialized");
}

int NetClient::AddServerAddrV4(const char *ipv4) {
        struct sockaddr_in addr_v4;

        if (Addresses::parseAddrV4(&addr_v4, ipv4, APP_PORT) != 0) {
            return -1;
        }

        server_addr_v4 = addr_v4;
        state = NetClientState::CLIENT_READY;

        LOG_MSG(LOG_INFO, "server addr added");
        return 0;
}

void NetClient::Close() {
    if (close_socket(socket) != 0) {
        NetLogger::sysLogExit("close socket failure");
    }

    state = NetClientState::CLIENT_CLOSED;
    LOG_MSG(LOG_INFO, "client closed");
}





