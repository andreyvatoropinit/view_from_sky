// MESSAGE ANALYZER_TARGET_DATA support class

#pragma once

namespace mavlink {
namespace target_analyzer {
namespace msg {

/**
 * @brief ANALYZER_TARGET_DATA message
 *
 * TODO
 */
struct ANALYZER_TARGET_DATA : mavlink::Message {
    static constexpr msgid_t MSG_ID = 10800;
    static constexpr size_t LENGTH = 67;
    static constexpr size_t MIN_LENGTH = 67;
    static constexpr uint8_t CRC_EXTRA = 233;
    static constexpr auto NAME = "ANALYZER_TARGET_DATA";


    uint8_t target_status; /*<  Target status */
    uint32_t target_global_id; /*<  Target Global ID */
    uint32_t target_local_id; /*<  Target Local ID. (if target not from local source than LocalID=GlobalID) */
    uint32_t target_source_id; /*<  Target source ID */
    uint64_t timestamp; /*< [us] Timestamp in microseconds */
    uint8_t confidence; /*< [%] Confidence in percents [0..100] */
    uint8_t target_type; /*<  Type of target */
    float azimuth; /*< [deg] Target azimuth */
    float elevation; /*< [deg] Target elevation */
    float distance; /*< [m] Target distance */
    float size_horizontal; /*< [deg] Target horizontal size */
    float size_vertical; /*< [deg] Target vertical size */
    float x; /*< [m] Target world space position coordinate X. In meters */
    float y; /*< [m] Target world space position coordinate Y. In meters */
    float z; /*< [m] Target world space position coordinate Z. In meters */
    float vx; /*< [m/s] Target world space velocity along X axis. In meters per second */
    float vy; /*< [m/s] Target world space velocity along Y axis. In meters per second */
    float vz; /*< [m/s] Target world space velocity along Z axis. In meters per second */


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
        ss << "  target_status: " << +target_status << std::endl;
        ss << "  target_global_id: " << target_global_id << std::endl;
        ss << "  target_local_id: " << target_local_id << std::endl;
        ss << "  target_source_id: " << target_source_id << std::endl;
        ss << "  timestamp: " << timestamp << std::endl;
        ss << "  confidence: " << +confidence << std::endl;
        ss << "  target_type: " << +target_type << std::endl;
        ss << "  azimuth: " << azimuth << std::endl;
        ss << "  elevation: " << elevation << std::endl;
        ss << "  distance: " << distance << std::endl;
        ss << "  size_horizontal: " << size_horizontal << std::endl;
        ss << "  size_vertical: " << size_vertical << std::endl;
        ss << "  x: " << x << std::endl;
        ss << "  y: " << y << std::endl;
        ss << "  z: " << z << std::endl;
        ss << "  vx: " << vx << std::endl;
        ss << "  vy: " << vy << std::endl;
        ss << "  vz: " << vz << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << timestamp;                     // offset: 0
        map << target_global_id;              // offset: 8
        map << target_local_id;               // offset: 12
        map << target_source_id;              // offset: 16
        map << azimuth;                       // offset: 20
        map << elevation;                     // offset: 24
        map << distance;                      // offset: 28
        map << size_horizontal;               // offset: 32
        map << size_vertical;                 // offset: 36
        map << x;                             // offset: 40
        map << y;                             // offset: 44
        map << z;                             // offset: 48
        map << vx;                            // offset: 52
        map << vy;                            // offset: 56
        map << vz;                            // offset: 60
        map << target_status;                 // offset: 64
        map << confidence;                    // offset: 65
        map << target_type;                   // offset: 66
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> timestamp;                     // offset: 0
        map >> target_global_id;              // offset: 8
        map >> target_local_id;               // offset: 12
        map >> target_source_id;              // offset: 16
        map >> azimuth;                       // offset: 20
        map >> elevation;                     // offset: 24
        map >> distance;                      // offset: 28
        map >> size_horizontal;               // offset: 32
        map >> size_vertical;                 // offset: 36
        map >> x;                             // offset: 40
        map >> y;                             // offset: 44
        map >> z;                             // offset: 48
        map >> vx;                            // offset: 52
        map >> vy;                            // offset: 56
        map >> vz;                            // offset: 60
        map >> target_status;                 // offset: 64
        map >> confidence;                    // offset: 65
        map >> target_type;                   // offset: 66
    }
};

} // namespace msg
} // namespace target_analyzer
} // namespace mavlink
