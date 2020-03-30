#pragma once
// MESSAGE MICROSERVICE_REQUEST_DATA PACKING

#define MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA 10002

MAVPACKED(
typedef struct __mavlink_microservice_request_data_t {
 uint32_t request_id; /*<  Request data with ID. Microservice MUST reply apropriate with .._DATA message on this request. Data ID SHOULD be specified in microservice file as enum.*/
}) mavlink_microservice_request_data_t;

#define MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN 4
#define MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_MIN_LEN 4
#define MAVLINK_MSG_ID_10002_LEN 4
#define MAVLINK_MSG_ID_10002_MIN_LEN 4

#define MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_CRC 40
#define MAVLINK_MSG_ID_10002_CRC 40



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MICROSERVICE_REQUEST_DATA { \
    10002, \
    "MICROSERVICE_REQUEST_DATA", \
    1, \
    {  { "request_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_microservice_request_data_t, request_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MICROSERVICE_REQUEST_DATA { \
    "MICROSERVICE_REQUEST_DATA", \
    1, \
    {  { "request_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_microservice_request_data_t, request_id) }, \
         } \
}
#endif

/**
 * @brief Pack a microservice_request_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param request_id  Request data with ID. Microservice MUST reply apropriate with .._DATA message on this request. Data ID SHOULD be specified in microservice file as enum.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_microservice_request_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t request_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN];
    _mav_put_uint32_t(buf, 0, request_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN);
#else
    mavlink_microservice_request_data_t packet;
    packet.request_id = request_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_CRC);
}

/**
 * @brief Pack a microservice_request_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_id  Request data with ID. Microservice MUST reply apropriate with .._DATA message on this request. Data ID SHOULD be specified in microservice file as enum.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_microservice_request_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t request_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN];
    _mav_put_uint32_t(buf, 0, request_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN);
#else
    mavlink_microservice_request_data_t packet;
    packet.request_id = request_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_CRC);
}

/**
 * @brief Encode a microservice_request_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param microservice_request_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_microservice_request_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_microservice_request_data_t* microservice_request_data)
{
    return mavlink_msg_microservice_request_data_pack(system_id, component_id, msg, microservice_request_data->request_id);
}

/**
 * @brief Encode a microservice_request_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param microservice_request_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_microservice_request_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_microservice_request_data_t* microservice_request_data)
{
    return mavlink_msg_microservice_request_data_pack_chan(system_id, component_id, chan, msg, microservice_request_data->request_id);
}

/**
 * @brief Send a microservice_request_data message
 * @param chan MAVLink channel to send the message
 *
 * @param request_id  Request data with ID. Microservice MUST reply apropriate with .._DATA message on this request. Data ID SHOULD be specified in microservice file as enum.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_microservice_request_data_send(mavlink_channel_t chan, uint32_t request_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN];
    _mav_put_uint32_t(buf, 0, request_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA, buf, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_CRC);
#else
    mavlink_microservice_request_data_t packet;
    packet.request_id = request_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA, (const char *)&packet, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_CRC);
#endif
}

/**
 * @brief Send a microservice_request_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_microservice_request_data_send_struct(mavlink_channel_t chan, const mavlink_microservice_request_data_t* microservice_request_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_microservice_request_data_send(chan, microservice_request_data->request_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA, (const char *)microservice_request_data, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_microservice_request_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t request_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, request_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA, buf, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_CRC);
#else
    mavlink_microservice_request_data_t *packet = (mavlink_microservice_request_data_t *)msgbuf;
    packet->request_id = request_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA, (const char *)packet, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_MIN_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE MICROSERVICE_REQUEST_DATA UNPACKING


/**
 * @brief Get field request_id from microservice_request_data message
 *
 * @return  Request data with ID. Microservice MUST reply apropriate with .._DATA message on this request. Data ID SHOULD be specified in microservice file as enum.
 */
static inline uint32_t mavlink_msg_microservice_request_data_get_request_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a microservice_request_data message into a struct
 *
 * @param msg The message to decode
 * @param microservice_request_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_microservice_request_data_decode(const mavlink_message_t* msg, mavlink_microservice_request_data_t* microservice_request_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    microservice_request_data->request_id = mavlink_msg_microservice_request_data_get_request_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN? msg->len : MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN;
        memset(microservice_request_data, 0, MAVLINK_MSG_ID_MICROSERVICE_REQUEST_DATA_LEN);
    memcpy(microservice_request_data, _MAV_PAYLOAD(msg), len);
#endif
}
