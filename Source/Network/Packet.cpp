//
// Created by pedro-souza on 22/10/2025.
//
#include "Packet.h"
#include "NetUtils.h"
#include  "Platforms.h"
#include <cstring>
#include  <cstdio>

NetPacket::NetPacket()
:sync1(PACKET_SYNC_BYTES)
,sync2(PACKET_SYNC_BYTES)
,state(PACKET_HOLD)
,sequence(0)
,flag(0)
,nonce(0)
,length(0)
,checksum(0)
,data{}
{}

NetPacket::NetPacket(const uint16_t _sequence, const uint8_t _flag, const uint32_t _nonce)
:sync1(PACKET_SYNC_BYTES)
,sync2(PACKET_SYNC_BYTES)
,state(PACKET_HOLD)
,sequence(_sequence)
,flag(_flag)
,nonce(_nonce)
,length(0)
,checksum(0)
,data{}
{}

void NetPacket::BuildPacket() {
    if (state != PACKET_HOLD) {
        return;
    }

    sync1 = htonl(sync1);
    sync2 = htonl(sync2);
    sequence = htons(sequence);
    nonce = htonl(nonce);

    state = PACKET_READY;

    const uint16_t _length = length;
    length = htons(length);

    const size_t packetSize = PACKET_HEADER_BYTES + _length;
    checksum = NetUtils::getNetChecksum(this, packetSize);
    checksum = htons(checksum);
}

bool NetPacket::IsValid() const {
    if (state != PACKET_READY) {
        return false;
    }

    if(sync1 != htonl(PACKET_SYNC_BYTES) ||
       sync2 != htonl(PACKET_SYNC_BYTES)) {
        return false;
    }

    const uint16_t _length = ntohs(length);
    if(_length > MAX_PACKET_DATA_BYTES){
        return false;
    }

    NetPacket temp{};
    memcpy(&temp, this, sizeof(NetPacket));
    temp.checksum = 0;

    const size_t packetSize = PACKET_HEADER_BYTES + _length;

    if (const uint16_t calculatedChecksum = NetUtils::getNetChecksum(&temp, packetSize);
        calculatedChecksum != checksum) {
        return false;
    }

    return true;
}
