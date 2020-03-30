/** @file
 *	@brief MAVLink comm protocol generated from target_analyzer.xml
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
namespace target_analyzer {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (trought @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 4> MESSAGE_ENTRIES {{ {10000, 215, 16, 16, 0, 0, 0}, {10001, 23, 1, 1, 0, 0, 0}, {10002, 40, 4, 4, 0, 0, 0}, {10800, 233, 67, 67, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 2;


// ENUM DEFINITIONS


/** @brief  */
enum class ANALYZER_REQUEST
{
    TARGET_DATA=0, /* TODO | */
};

//! ANALYZER_REQUEST ENUM_END
constexpr auto ANALYZER_REQUEST_ENUM_END = 1;

/** @brief TODO */
enum class ANALYZER_TARGET_STATE : uint8_t
{
    LOCKED=1, /* ALL subsystems are OK | */
    PREDICTED=2, /* ALL subsystems are OK | */
    LOST=3, /* ALL subsystems are OK | */
};

//! ANALYZER_TARGET_STATE ENUM_END
constexpr auto ANALYZER_TARGET_STATE_ENUM_END = 4;


} // namespace target_analyzer
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_analyzer_target_data.hpp"

// base include
#include "../microservice/microservice.hpp"
