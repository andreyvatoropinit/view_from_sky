/** @file
 *  @brief MAVLink comm protocol generated from target_analyzer.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_TARGET_ANALYZER_H
#define MAVLINK_TARGET_ANALYZER_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_TARGET_ANALYZER.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{10000, 215, 16, 16, 0, 0, 0}, {10001, 23, 1, 1, 0, 0, 0}, {10002, 40, 4, 4, 0, 0, 0}, {10800, 233, 67, 67, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_TARGET_ANALYZER

// ENUM DEFINITIONS


/** @brief  */
#ifndef HAVE_ENUM_ANALYZER_REQUEST
#define HAVE_ENUM_ANALYZER_REQUEST
typedef enum ANALYZER_REQUEST
{
   ANALYZER_REQUEST_TARGET_DATA=0, /* TODO | */
   ANALYZER_REQUEST_ENUM_END=1, /*  | */
} ANALYZER_REQUEST;
#endif

/** @brief TODO */
#ifndef HAVE_ENUM_ANALYZER_TARGET_STATE
#define HAVE_ENUM_ANALYZER_TARGET_STATE
typedef enum ANALYZER_TARGET_STATE
{
   ANALYZER_TARGET_STATE_LOCKED=1, /* ALL subsystems are OK | */
   ANALYZER_TARGET_STATE_PREDICTED=2, /* ALL subsystems are OK | */
   ANALYZER_TARGET_STATE_LOST=3, /* ALL subsystems are OK | */
   ANALYZER_TARGET_STATE_ENUM_END=4, /*  | */
} ANALYZER_TARGET_STATE;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_analyzer_target_data.h"

// base include
#include "../microservice/microservice.h"

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_MICROSERVICE_HEARTBEAT_DATA, MAVLINK_MESSAGE_INFO_MICROSERVICE_COMMAND, MAVLINK_MESSAGE_INFO_MICROSERVICE_REQUEST_DATA, MAVLINK_MESSAGE_INFO_ANALYZER_TARGET_DATA}
# define MAVLINK_MESSAGE_NAMES {{ "ANALYZER_TARGET_DATA", 10800 }, { "MICROSERVICE_COMMAND", 10001 }, { "MICROSERVICE_HEARTBEAT_DATA", 10000 }, { "MICROSERVICE_REQUEST_DATA", 10002 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_TARGET_ANALYZER_H
