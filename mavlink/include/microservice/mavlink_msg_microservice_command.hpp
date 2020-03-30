// MESSAGE MICROSERVICE_COMMAND support class

#pragma once

namespace mavlink {
namespace microservice {
namespace msg {

/**
 * @brief MICROSERVICE_COMMAND message
 *
 * ��������� ������ ������������
 */
struct MICROSERVICE_COMMAND : mavlink::Message {
    static constexpr msgid_t MSG_ID = 10001;
    static constexpr size_t LENGTH = 1;
    static constexpr size_t MIN_LENGTH = 1;
    static constexpr uint8_t CRC_EXTRA = 23;
    static constexpr auto NAME = "MICROSERVICE_COMMAND";


    uint8_t command; /*<  Microservice command */


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
        ss << "  command: " << +command << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << command;                       // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> command;                       // offset: 0
    }
};

} // namespace msg
} // namespace microservice
} // namespace mavlink
