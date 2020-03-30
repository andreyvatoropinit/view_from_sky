#pragma once
// MESSAGE MICROSERVICE_HEARTBEAT_DATA PACKING

#define MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA 10000

MAVPACKED(
typedef struct __mavlink_microservice_heartbeat_data_t {
 uint64_t time_since_boot; /*< [us] Time since microservice boot in microseconds*/
 uint32_t flags; /*<  Microservice status flags*/
 uint32_t service_type; /*<  Micorservice type ID*/
}) mavlink_microservice_heartbeat_data_t;

#define MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN 16
#define MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_MIN_LEN 16
#define MAVLINK_MSG_ID_10000_LEN 16
#define MAVLINK_MSG_ID_10000_MIN_LEN 16

#define MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_CRC 215
#define MAVLINK_MSG_ID_10000_CRC 215



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MICROSERVICE_HEARTBEAT_DATA { \
    10000, \
    "MICROSERVICE_HEARTBEAT_DATA", \
    3, \
    {  { "flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_microservice_heartbeat_data_t, flags) }, \
         { "service_type", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_microservice_heartbeat_data_t, service_type) }, \
         { "time_since_boot", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_microservice_heartbeat_data_t, time_since_boot) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MICROSERVICE_HEARTBEAT_DATA { \
    "MICROSERVICE_HEARTBEAT_DATA", \
    3, \
    {  { "flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_microservice_heartbeat_data_t, flags) }, \
         { "service_type", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_microservice_heartbeat_data_t, service_type) }, \
         { "time_since_boot", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_microservice_heartbeat_data_t, time_since_boot) }, \
         } \
}
#endif

/**
 * @brief Pack a microservice_heartbeat_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param flags  Microservice status flags
 * @param service_type  Micorservice type ID
 * @param time_since_boot [us] Time since microservice boot in microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_microservice_heartbeat_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t flags, uint32_t service_type, uint64_t time_since_boot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN];
    _mav_put_uint64_t(buf, 0, time_since_boot);
    _mav_put_uint32_t(buf, 8, flags);
    _mav_put_uint32_t(buf, 12, service_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN);
#else
    mavlink_microservice_heartbeat_data_t packet;
    packet.time_since_boot = time_since_boot;
    packet.flags = flags;
    packet.service_type = service_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_CRC);
}

/**
 * @brief Pack a microservice_heartbeat_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param flags  Microservice status flags
 * @param service_type  Micorservice type ID
 * @param time_since_boot [us] Time since microservice boot in microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_microservice_heartbeat_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t flags,uint32_t service_type,uint64_t time_since_boot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN];
    _mav_put_uint64_t(buf, 0, time_since_boot);
    _mav_put_uint32_t(buf, 8, flags);
    _mav_put_uint32_t(buf, 12, service_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN);
#else
    mavlink_microservice_heartbeat_data_t packet;
    packet.time_since_boot = time_since_boot;
    packet.flags = flags;
    packet.service_type = service_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_CRC);
}

/**
 * @brief Encode a microservice_heartbeat_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param microservice_heartbeat_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_microservice_heartbeat_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_microservice_heartbeat_data_t* microservice_heartbeat_data)
{
    return mavlink_msg_microservice_heartbeat_data_pack(system_id, component_id, msg, microservice_heartbeat_data->flags, microservice_heartbeat_data->service_type, microservice_heartbeat_data->time_since_boot);
}

/**
 * @brief Encode a microservice_heartbeat_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param microservice_heartbeat_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_microservice_heartbeat_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_microservice_heartbeat_data_t* microservice_heartbeat_data)
{
    return mavlink_msg_microservice_heartbeat_data_pack_chan(system_id, component_id, chan, msg, microservice_heartbeat_data->flags, microservice_heartbeat_data->service_type, microservice_heartbeat_data->time_since_boot);
}

/**
 * @brief Send a microservice_heartbeat_data message
 * @param chan MAVLink channel to send the message
 *
 * @param flags  Microservice status flags
 * @param service_type  Micorservice type ID
 * @param time_since_boot [us] Time since microservice boot in microseconds
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_microservice_heartbeat_data_send(mavlink_channel_t chan, uint32_t flags, uint32_t service_type, uint64_t time_since_boot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN];
    _mav_put_uint64_t(buf, 0, time_since_boot);
    _mav_put_uint32_t(buf, 8, flags);
    _mav_put_uint32_t(buf, 12, service_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA, buf, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_CRC);
#else
    mavlink_microservice_heartbeat_data_t packet;
    packet.time_since_boot = time_since_boot;
    packet.flags = flags;
    packet.service_type = service_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA, (const char *)&packet, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_CRC);
#endif
}

/**
 * @brief Send a microservice_heartbeat_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_microservice_heartbeat_data_send_struct(mavlink_channel_t chan, const mavlink_microservice_heartbeat_data_t* microservice_heartbeat_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_microservice_heartbeat_data_send(chan, microservice_heartbeat_data->flags, microservice_heartbeat_data->service_type, microservice_heartbeat_data->time_since_boot);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA, (const char *)microservice_heartbeat_data, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_microservice_heartbeat_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t flags, uint32_t service_type, uint64_t time_since_boot)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_since_boot);
    _mav_put_uint32_t(buf, 8, flags);
    _mav_put_uint32_t(buf, 12, service_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA, buf, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_CRC);
#else
    mavlink_microservice_heartbeat_data_t *packet = (mavlink_microservice_heartbeat_data_t *)msgbuf;
    packet->time_since_boot = time_since_boot;
    packet->flags = flags;
    packet->service_type = service_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA, (const char *)packet, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE MICROSERVICE_HEARTBEAT_DATA UNPACKING


/**
 * @brief Get field flags from microservice_heartbeat_data message
 *
 * @return  Microservice status flags
 */
static inline uint32_t mavlink_msg_microservice_heartbeat_data_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field service_type from microservice_heartbeat_data message
 *
 * @return  Micorservice type ID
 */
static inline uint32_t mavlink_msg_microservice_heartbeat_data_get_service_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field time_since_boot from microservice_heartbeat_data message
 *
 * @return [us] Time since microservice boot in microseconds
 */
static inline uint64_t mavlink_msg_microservice_heartbeat_data_get_time_since_boot(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a microservice_heartbeat_data message into a struct
 *
 * @param msg The message to decode
 * @param microservice_heartbeat_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_microservice_heartbeat_data_decode(const mavlink_message_t* msg, mavlink_microservice_heartbeat_data_t* microservice_heartbeat_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    microservice_heartbeat_data->time_since_boot = mavlink_msg_microservice_heartbeat_data_get_time_since_boot(msg);
    microservice_heartbeat_data->flags = mavlink_msg_microservice_heartbeat_data_get_flags(msg);
    microservice_heartbeat_data->service_type = mavlink_msg_microservice_heartbeat_data_get_service_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN? msg->len : MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN;
        memset(microservice_heartbeat_data, 0, MAVLINK_MSG_ID_MICROSERVICE_HEARTBEAT_DATA_LEN);
    memcpy(microservice_heartbeat_data, _MAV_PAYLOAD(msg), len);
#endif
}
