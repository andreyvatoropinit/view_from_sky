/** @file
 *  @brief MAVLink comm protocol generated from microservice.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_MICROSERVICE_H
#define MAVLINK_MICROSERVICE_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_MICROSERVICE.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 1

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{10000, 215, 16, 16, 0, 0, 0}, {10001, 23, 1, 1, 0, 0, 0}, {10002, 40, 4, 4, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_MICROSERVICE

// ENUM DEFINITIONS


/** @brief  */
#ifndef HAVE_ENUM_MICROSERVICE_FLAG
#define HAVE_ENUM_MICROSERVICE_FLAG
typedef enum MICROSERVICE_FLAG
{
   MICROSERVICE_FLAG_IS_HEALTHY=1, /* Флаг, указывающий на то, что сервис "жив" | */
   MICROSERVICE_FLAG_ENUM_END=2, /*  | */
} MICROSERVICE_FLAG;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MICROSERVICE_CMD
#define HAVE_ENUM_MICROSERVICE_CMD
typedef enum MICROSERVICE_CMD
{
   MICROSERVICE_CMD_START=1, /* Команда запуска сервиса | */
   MICROSERVICE_CMD_STOP=2, /* Команда остановки сервиса | */
   MICROSERVICE_CMD_RESTART=3, /* Команда перезапуска сервиса | */
   MICROSERVICE_CMD_ENUM_END=4, /*  | */
} MICROSERVICE_CMD;
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
#include "./mavlink_msg_microservice_heartbeat_data.h"
#include "./mavlink_msg_microservice_command.h"
#include "./mavlink_msg_microservice_request_data.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 1

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_MICROSERVICE_HEARTBEAT_DATA, MAVLINK_MESSAGE_INFO_MICROSERVICE_COMMAND, MAVLINK_MESSAGE_INFO_MICROSERVICE_REQUEST_DATA}
# define MAVLINK_MESSAGE_NAMES {{ "MICROSERVICE_COMMAND", 10001 }, { "MICROSERVICE_HEARTBEAT_DATA", 10000 }, { "MICROSERVICE_REQUEST_DATA", 10002 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_MICROSERVICE_H
