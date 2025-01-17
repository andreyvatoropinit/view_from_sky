// MESSAGE MICROSERVICE_REQUEST_DATA support class

#pragma once

namespace mavlink {
namespace microservice {
namespace msg {

/**
 * @brief MICROSERVICE_REQUEST_DATA message
 *
 * ������, ������� ����� ��������� � �������
 */
struct MICROSERVICE_REQUEST_DATA : mavlink::Message {
    static constexpr msgid_t MSG_ID = 10002;
    static constexpr size_t LENGTH = 4;
    static constexpr size_t MIN_LENGTH = 4;
    static constexpr uint8_t CRC_EXTRA = 40;
    static constexpr auto NAME = "MICROSERVICE_REQUEST_DATA";


    uint32_t request_id; /*<  Request data with ID. Microservice MUST reply apropriate with .._DATA message on this request. Data ID SHOULD be specified in microservice file as enum. */


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
        ss << "  request_id: " << request_id << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << request_id;                    // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> request_id;                    // offset: 0
    }
};

} // namespace msg
} // namespace microservice
} // namespace mavlink
