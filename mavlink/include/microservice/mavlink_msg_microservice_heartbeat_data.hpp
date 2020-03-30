// MESSAGE MICROSERVICE_HEARTBEAT_DATA support class

#pragma once

namespace mavlink {
namespace microservice {
namespace msg {

/**
 * @brief MICROSERVICE_HEARTBEAT_DATA message
 *
 * Структура данных о состоянии сервиса
 */
struct MICROSERVICE_HEARTBEAT_DATA : mavlink::Message {
    static constexpr msgid_t MSG_ID = 10000;
    static constexpr size_t LENGTH = 16;
    static constexpr size_t MIN_LENGTH = 16;
    static constexpr uint8_t CRC_EXTRA = 215;
    static constexpr auto NAME = "MICROSERVICE_HEARTBEAT_DATA";


    uint32_t flags; /*<  Microservice status flags */
    uint32_t service_type; /*<  Micorservice type ID */
    uint64_t time_since_boot; /*< [us] Time since microservice boot in microseconds */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  flags: " << flags << std::endl;
        ss << "  service_type: " << service_type << std::endl;
        ss << "  time_since_boot: " << time_since_boot << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_since_boot;               // offset: 0
        map << flags;                         // offset: 8
        map << service_type;                  // offset: 12
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_since_boot;               // offset: 0
        map >> flags;                         // offset: 8
        map >> service_type;                  // offset: 12
    }
};

} // namespace msg
} // namespace microservice
} // namespace mavlink
