//
// Created by pedro-souza on 22/10/2025.
//

#ifndef PACKET_H
#define PACKET_H

#include <cstdint>
#include <cstdlib>

enum class DataType : uint8_t {
    UINT32_TYPE = 0,
    INT32_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    BOOL_TYPE,
    STRING_TYPE
};

#pragma pack(1)
class NetPacket {
public:
    NetPacket();
    NetPacket(uint16_t _sequence, uint8_t _flag, uint32_t _nonce);
    void BuildPacket();
    void PrintPacket() const;
    [[nodiscard]] bool IsValid() const;

    // public packet constants
    static constexpr size_t MAX_PACKET_DATA_BYTES = 1024;
    static constexpr size_t MAX_PACKET_DATA_STRING_BYTES = 256;
    static constexpr size_t PACKET_HEADER_BYTES = 20;

    // public packet flags
    static constexpr uint8_t SYN_FLAG = 0x01;
    static constexpr uint8_t SYN_ACK_FLAG = 0x02;
    static constexpr uint8_t ACK_FLAG = 0x03;
    static constexpr uint8_t DATA_FLAG = 0x04;
    static constexpr uint8_t END_FLAG = 0x05;
    static constexpr uint8_t RST_FLAG = 0x06;

private:
    // packet content
    uint32_t sync1;
    uint32_t sync2;
    uint8_t state;
    uint16_t sequence;
    uint8_t flag;
    uint32_t nonce;
    uint16_t length;
    uint16_t checksum;
    char data[1024];

    // packet constants
    static constexpr uint32_t PACKET_SYNC_BYTES = 0x554E4554;
    static constexpr uint8_t PACKET_HOLD = 1;
    static constexpr uint8_t PACKET_READY = 2;
};
#pragma pack(0)

#endif // PACKET_H