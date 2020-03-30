/** @file
 *	@brief MAVLink comm protocol generated from microservice.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <array>
#include <cstdint>
#include <sstream>

#ifndef MAVLINK_STX
#define MAVLINK_STX 253
#endif

#include "../message.hpp"

namespace mavlink {
namespace microservice {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (trought @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 3> MESSAGE_ENTRIES {{ {10000, 215, 16, 16, 0, 0, 0}, {10001, 23, 1, 1, 0, 0, 0}, {10002, 40, 4, 4, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 2;


// ENUM DEFINITIONS


/** @brief  */
enum class MICROSERVICE_FLAG : uint32_t
{
    IS_HEALTHY=1, /* Флаг, указывающий на то, что сервис "жив" | */
};

//! MICROSERVICE_FLAG ENUM_END
constexpr auto MICROSERVICE_FLAG_ENUM_END = 2;

/** @brief  */
enum class MICROSERVICE_CMD : uint8_t
{
    START=1, /* Команда запуска сервиса | */
    STOP=2, /* Команда остановки сервиса | */
    RESTART=3, /* Команда перезапуска сервиса | */
};

//! MICROSERVICE_CMD ENUM_END
constexpr auto MICROSERVICE_CMD_ENUM_END = 4;


} // namespace microservice
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_microservice_heartbeat_data.hpp"
#include "./mavlink_msg_microservice_command.hpp"
#include "./mavlink_msg_microservice_request_data.hpp"

// base include

