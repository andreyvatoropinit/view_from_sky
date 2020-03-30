#pragma once
// MESSAGE MICROSERVICE_COMMAND PACKING

#define MAVLINK_MSG_ID_MICROSERVICE_COMMAND 10001

MAVPACKED(
typedef struct __mavlink_microservice_command_t {
 uint8_t command; /*<  Microservice command*/
}) mavlink_microservice_command_t;

#define MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN 1
#define MAVLINK_MSG_ID_MICROSERVICE_COMMAND_MIN_LEN 1
#define MAVLINK_MSG_ID_10001_LEN 1
#define MAVLINK_MSG_ID_10001_MIN_LEN 1

#define MAVLINK_MSG_ID_MICROSERVICE_COMMAND_CRC 23
#define MAVLINK_MSG_ID_10001_CRC 23



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MICROSERVICE_COMMAND { \
    10001, \
    "MICROSERVICE_COMMAND", \
    1, \
    {  { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_microservice_command_t, command) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MICROSERVICE_COMMAND { \
    "MICROSERVICE_COMMAND", \
    1, \
    {  { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_microservice_command_t, command) }, \
         } \
}
#endif

/**
 * @brief Pack a microservice_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param command  Microservice command
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_microservice_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN];
    _mav_put_uint8_t(buf, 0, command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN);
#else
    mavlink_microservice_command_t packet;
    packet.command = command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MICROSERVICE_COMMAND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_CRC);
}

/**
 * @brief Pack a microservice_command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command  Microservice command
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_microservice_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN];
    _mav_put_uint8_t(buf, 0, command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN);
#else
    mavlink_microservice_command_t packet;
    packet.command = command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MICROSERVICE_COMMAND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_CRC);
}

/**
 * @brief Encode a microservice_command struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param microservice_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_microservice_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_microservice_command_t* microservice_command)
{
    return mavlink_msg_microservice_command_pack(system_id, component_id, msg, microservice_command->command);
}

/**
 * @brief Encode a microservice_command struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param microservice_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_microservice_command_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_microservice_command_t* microservice_command)
{
    return mavlink_msg_microservice_command_pack_chan(system_id, component_id, chan, msg, microservice_command->command);
}

/**
 * @brief Send a microservice_command message
 * @param chan MAVLink channel to send the message
 *
 * @param command  Microservice command
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_microservice_command_send(mavlink_channel_t chan, uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN];
    _mav_put_uint8_t(buf, 0, command);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_COMMAND, buf, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_CRC);
#else
    mavlink_microservice_command_t packet;
    packet.command = command;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_COMMAND, (const char *)&packet, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_CRC);
#endif
}

/**
 * @brief Send a microservice_command message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_microservice_command_send_struct(mavlink_channel_t chan, const mavlink_microservice_command_t* microservice_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_microservice_command_send(chan, microservice_command->command);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_COMMAND, (const char *)microservice_command, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_CRC);
#endif
}

#if MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_microservice_command_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, command);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_COMMAND, buf, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_CRC);
#else
    mavlink_microservice_command_t *packet = (mavlink_microservice_command_t *)msgbuf;
    packet->command = command;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_COMMAND, (const char *)packet, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_CRC);
#endif
}
#endif

#endif

// MESSAGE MICROSERVICE_COMMAND UNPACKING


/**
 * @brief Get field command from microservice_command message
 *
 * @return  Microservice command
 */
static inline uint8_t mavlink_msg_microservice_command_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a microservice_command message into a struct
 *
 * @param msg The message to decode
 * @param microservice_command C-struct to decode the message contents into
 */
static inline void mavlink_msg_microservice_command_decode(const mavlink_message_t* msg, mavlink_microservice_command_t* microservice_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    microservice_command->command = mavlink_msg_microservice_command_get_command(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN? msg->len : MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN;
        memset(microservice_command, 0, MAVLINK_MSG_ID_MICROSERVICE_COMMAND_LEN);
    memcpy(microservice_command, _MAV_PAYLOAD(msg), len);
#endif
}
