#pragma once
// MESSAGE ANALYZER_TARGET_DATA PACKING

#define MAVLINK_MSG_ID_ANALYZER_TARGET_DATA 10800

MAVPACKED(
typedef struct __mavlink_analyzer_target_data_t {
 uint64_t timestamp; /*< [us] Timestamp in microseconds*/
 uint32_t target_global_id; /*<  Target Global ID*/
 uint32_t target_local_id; /*<  Target Local ID. (if target not from local source than LocalID=GlobalID)*/
 uint32_t target_source_id; /*<  Target source ID*/
 float azimuth; /*< [deg] Target azimuth*/
 float elevation; /*< [deg] Target elevation*/
 float distance; /*< [m] Target distance*/
 float size_horizontal; /*< [deg] Target horizontal size*/
 float size_vertical; /*< [deg] Target vertical size*/
 float x; /*< [m] Target world space position coordinate X. In meters*/
 float y; /*< [m] Target world space position coordinate Y. In meters*/
 float z; /*< [m] Target world space position coordinate Z. In meters*/
 float vx; /*< [m/s] Target world space velocity along X axis. In meters per second*/
 float vy; /*< [m/s] Target world space velocity along Y axis. In meters per second*/
 float vz; /*< [m/s] Target world space velocity along Z axis. In meters per second*/
 uint8_t target_status; /*<  Target status*/
 uint8_t confidence; /*< [%] Confidence in percents [0..100]*/
 uint8_t target_type; /*<  Type of target*/
}) mavlink_analyzer_target_data_t;

#define MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN 67
#define MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN 67
#define MAVLINK_MSG_ID_10800_LEN 67
#define MAVLINK_MSG_ID_10800_MIN_LEN 67

#define MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_CRC 233
#define MAVLINK_MSG_ID_10800_CRC 233



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ANALYZER_TARGET_DATA { \
    10800, \
    "ANALYZER_TARGET_DATA", \
    18, \
    {  { "target_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 64, offsetof(mavlink_analyzer_target_data_t, target_status) }, \
         { "target_global_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_analyzer_target_data_t, target_global_id) }, \
         { "target_local_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_analyzer_target_data_t, target_local_id) }, \
         { "target_source_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_analyzer_target_data_t, target_source_id) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_analyzer_target_data_t, timestamp) }, \
         { "confidence", NULL, MAVLINK_TYPE_UINT8_T, 0, 65, offsetof(mavlink_analyzer_target_data_t, confidence) }, \
         { "target_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 66, offsetof(mavlink_analyzer_target_data_t, target_type) }, \
         { "azimuth", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_analyzer_target_data_t, azimuth) }, \
         { "elevation", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_analyzer_target_data_t, elevation) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_analyzer_target_data_t, distance) }, \
         { "size_horizontal", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_analyzer_target_data_t, size_horizontal) }, \
         { "size_vertical", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_analyzer_target_data_t, size_vertical) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_analyzer_target_data_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_analyzer_target_data_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_analyzer_target_data_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_analyzer_target_data_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_analyzer_target_data_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_analyzer_target_data_t, vz) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ANALYZER_TARGET_DATA { \
    "ANALYZER_TARGET_DATA", \
    18, \
    {  { "target_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 64, offsetof(mavlink_analyzer_target_data_t, target_status) }, \
         { "target_global_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_analyzer_target_data_t, target_global_id) }, \
         { "target_local_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_analyzer_target_data_t, target_local_id) }, \
         { "target_source_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_analyzer_target_data_t, target_source_id) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_analyzer_target_data_t, timestamp) }, \
         { "confidence", NULL, MAVLINK_TYPE_UINT8_T, 0, 65, offsetof(mavlink_analyzer_target_data_t, confidence) }, \
         { "target_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 66, offsetof(mavlink_analyzer_target_data_t, target_type) }, \
         { "azimuth", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_analyzer_target_data_t, azimuth) }, \
         { "elevation", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_analyzer_target_data_t, elevation) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_analyzer_target_data_t, distance) }, \
         { "size_horizontal", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_analyzer_target_data_t, size_horizontal) }, \
         { "size_vertical", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_analyzer_target_data_t, size_vertical) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_analyzer_target_data_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_analyzer_target_data_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_analyzer_target_data_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_analyzer_target_data_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_analyzer_target_data_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_analyzer_target_data_t, vz) }, \
         } \
}
#endif

/**
 * @brief Pack a analyzer_target_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_status  Target status
 * @param target_global_id  Target Global ID
 * @param target_local_id  Target Local ID. (if target not from local source than LocalID=GlobalID)
 * @param target_source_id  Target source ID
 * @param timestamp [us] Timestamp in microseconds
 * @param confidence [%] Confidence in percents [0..100]
 * @param target_type  Type of target
 * @param azimuth [deg] Target azimuth
 * @param elevation [deg] Target elevation
 * @param distance [m] Target distance
 * @param size_horizontal [deg] Target horizontal size
 * @param size_vertical [deg] Target vertical size
 * @param x [m] Target world space position coordinate X. In meters
 * @param y [m] Target world space position coordinate Y. In meters
 * @param z [m] Target world space position coordinate Z. In meters
 * @param vx [m/s] Target world space velocity along X axis. In meters per second
 * @param vy [m/s] Target world space velocity along Y axis. In meters per second
 * @param vz [m/s] Target world space velocity along Z axis. In meters per second
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_analyzer_target_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_status, uint32_t target_global_id, uint32_t target_local_id, uint32_t target_source_id, uint64_t timestamp, uint8_t confidence, uint8_t target_type, float azimuth, float elevation, float distance, float size_horizontal, float size_vertical, float x, float y, float z, float vx, float vy, float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, target_global_id);
    _mav_put_uint32_t(buf, 12, target_local_id);
    _mav_put_uint32_t(buf, 16, target_source_id);
    _mav_put_float(buf, 20, azimuth);
    _mav_put_float(buf, 24, elevation);
    _mav_put_float(buf, 28, distance);
    _mav_put_float(buf, 32, size_horizontal);
    _mav_put_float(buf, 36, size_vertical);
    _mav_put_float(buf, 40, x);
    _mav_put_float(buf, 44, y);
    _mav_put_float(buf, 48, z);
    _mav_put_float(buf, 52, vx);
    _mav_put_float(buf, 56, vy);
    _mav_put_float(buf, 60, vz);
    _mav_put_uint8_t(buf, 64, target_status);
    _mav_put_uint8_t(buf, 65, confidence);
    _mav_put_uint8_t(buf, 66, target_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN);
#else
    mavlink_analyzer_target_data_t packet;
    packet.timestamp = timestamp;
    packet.target_global_id = target_global_id;
    packet.target_local_id = target_local_id;
    packet.target_source_id = target_source_id;
    packet.azimuth = azimuth;
    packet.elevation = elevation;
    packet.distance = distance;
    packet.size_horizontal = size_horizontal;
    packet.size_vertical = size_vertical;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.target_status = target_status;
    packet.confidence = confidence;
    packet.target_type = target_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ANALYZER_TARGET_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_CRC);
}

/**
 * @brief Pack a analyzer_target_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_status  Target status
 * @param target_global_id  Target Global ID
 * @param target_local_id  Target Local ID. (if target not from local source than LocalID=GlobalID)
 * @param target_source_id  Target source ID
 * @param timestamp [us] Timestamp in microseconds
 * @param confidence [%] Confidence in percents [0..100]
 * @param target_type  Type of target
 * @param azimuth [deg] Target azimuth
 * @param elevation [deg] Target elevation
 * @param distance [m] Target distance
 * @param size_horizontal [deg] Target horizontal size
 * @param size_vertical [deg] Target vertical size
 * @param x [m] Target world space position coordinate X. In meters
 * @param y [m] Target world space position coordinate Y. In meters
 * @param z [m] Target world space position coordinate Z. In meters
 * @param vx [m/s] Target world space velocity along X axis. In meters per second
 * @param vy [m/s] Target world space velocity along Y axis. In meters per second
 * @param vz [m/s] Target world space velocity along Z axis. In meters per second
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_analyzer_target_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_status,uint32_t target_global_id,uint32_t target_local_id,uint32_t target_source_id,uint64_t timestamp,uint8_t confidence,uint8_t target_type,float azimuth,float elevation,float distance,float size_horizontal,float size_vertical,float x,float y,float z,float vx,float vy,float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, target_global_id);
    _mav_put_uint32_t(buf, 12, target_local_id);
    _mav_put_uint32_t(buf, 16, target_source_id);
    _mav_put_float(buf, 20, azimuth);
    _mav_put_float(buf, 24, elevation);
    _mav_put_float(buf, 28, distance);
    _mav_put_float(buf, 32, size_horizontal);
    _mav_put_float(buf, 36, size_vertical);
    _mav_put_float(buf, 40, x);
    _mav_put_float(buf, 44, y);
    _mav_put_float(buf, 48, z);
    _mav_put_float(buf, 52, vx);
    _mav_put_float(buf, 56, vy);
    _mav_put_float(buf, 60, vz);
    _mav_put_uint8_t(buf, 64, target_status);
    _mav_put_uint8_t(buf, 65, confidence);
    _mav_put_uint8_t(buf, 66, target_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN);
#else
    mavlink_analyzer_target_data_t packet;
    packet.timestamp = timestamp;
    packet.target_global_id = target_global_id;
    packet.target_local_id = target_local_id;
    packet.target_source_id = target_source_id;
    packet.azimuth = azimuth;
    packet.elevation = elevation;
    packet.distance = distance;
    packet.size_horizontal = size_horizontal;
    packet.size_vertical = size_vertical;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.target_status = target_status;
    packet.confidence = confidence;
    packet.target_type = target_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ANALYZER_TARGET_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_CRC);
}

/**
 * @brief Encode a analyzer_target_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param analyzer_target_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_analyzer_target_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_analyzer_target_data_t* analyzer_target_data)
{
    return mavlink_msg_analyzer_target_data_pack(system_id, component_id, msg, analyzer_target_data->target_status, analyzer_target_data->target_global_id, analyzer_target_data->target_local_id, analyzer_target_data->target_source_id, analyzer_target_data->timestamp, analyzer_target_data->confidence, analyzer_target_data->target_type, analyzer_target_data->azimuth, analyzer_target_data->elevation, analyzer_target_data->distance, analyzer_target_data->size_horizontal, analyzer_target_data->size_vertical, analyzer_target_data->x, analyzer_target_data->y, analyzer_target_data->z, analyzer_target_data->vx, analyzer_target_data->vy, analyzer_target_data->vz);
}

/**
 * @brief Encode a analyzer_target_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param analyzer_target_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_analyzer_target_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_analyzer_target_data_t* analyzer_target_data)
{
    return mavlink_msg_analyzer_target_data_pack_chan(system_id, component_id, chan, msg, analyzer_target_data->target_status, analyzer_target_data->target_global_id, analyzer_target_data->target_local_id, analyzer_target_data->target_source_id, analyzer_target_data->timestamp, analyzer_target_data->confidence, analyzer_target_data->target_type, analyzer_target_data->azimuth, analyzer_target_data->elevation, analyzer_target_data->distance, analyzer_target_data->size_horizontal, analyzer_target_data->size_vertical, analyzer_target_data->x, analyzer_target_data->y, analyzer_target_data->z, analyzer_target_data->vx, analyzer_target_data->vy, analyzer_target_data->vz);
}

/**
 * @brief Send a analyzer_target_data message
 * @param chan MAVLink channel to send the message
 *
 * @param target_status  Target status
 * @param target_global_id  Target Global ID
 * @param target_local_id  Target Local ID. (if target not from local source than LocalID=GlobalID)
 * @param target_source_id  Target source ID
 * @param timestamp [us] Timestamp in microseconds
 * @param confidence [%] Confidence in percents [0..100]
 * @param target_type  Type of target
 * @param azimuth [deg] Target azimuth
 * @param elevation [deg] Target elevation
 * @param distance [m] Target distance
 * @param size_horizontal [deg] Target horizontal size
 * @param size_vertical [deg] Target vertical size
 * @param x [m] Target world space position coordinate X. In meters
 * @param y [m] Target world space position coordinate Y. In meters
 * @param z [m] Target world space position coordinate Z. In meters
 * @param vx [m/s] Target world space velocity along X axis. In meters per second
 * @param vy [m/s] Target world space velocity along Y axis. In meters per second
 * @param vz [m/s] Target world space velocity along Z axis. In meters per second
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_analyzer_target_data_send(mavlink_channel_t chan, uint8_t target_status, uint32_t target_global_id, uint32_t target_local_id, uint32_t target_source_id, uint64_t timestamp, uint8_t confidence, uint8_t target_type, float azimuth, float elevation, float distance, float size_horizontal, float size_vertical, float x, float y, float z, float vx, float vy, float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, target_global_id);
    _mav_put_uint32_t(buf, 12, target_local_id);
    _mav_put_uint32_t(buf, 16, target_source_id);
    _mav_put_float(buf, 20, azimuth);
    _mav_put_float(buf, 24, elevation);
    _mav_put_float(buf, 28, distance);
    _mav_put_float(buf, 32, size_horizontal);
    _mav_put_float(buf, 36, size_vertical);
    _mav_put_float(buf, 40, x);
    _mav_put_float(buf, 44, y);
    _mav_put_float(buf, 48, z);
    _mav_put_float(buf, 52, vx);
    _mav_put_float(buf, 56, vy);
    _mav_put_float(buf, 60, vz);
    _mav_put_uint8_t(buf, 64, target_status);
    _mav_put_uint8_t(buf, 65, confidence);
    _mav_put_uint8_t(buf, 66, target_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA, buf, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_CRC);
#else
    mavlink_analyzer_target_data_t packet;
    packet.timestamp = timestamp;
    packet.target_global_id = target_global_id;
    packet.target_local_id = target_local_id;
    packet.target_source_id = target_source_id;
    packet.azimuth = azimuth;
    packet.elevation = elevation;
    packet.distance = distance;
    packet.size_horizontal = size_horizontal;
    packet.size_vertical = size_vertical;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.target_status = target_status;
    packet.confidence = confidence;
    packet.target_type = target_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA, (const char *)&packet, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_CRC);
#endif
}

/**
 * @brief Send a analyzer_target_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_analyzer_target_data_send_struct(mavlink_channel_t chan, const mavlink_analyzer_target_data_t* analyzer_target_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_analyzer_target_data_send(chan, analyzer_target_data->target_status, analyzer_target_data->target_global_id, analyzer_target_data->target_local_id, analyzer_target_data->target_source_id, analyzer_target_data->timestamp, analyzer_target_data->confidence, analyzer_target_data->target_type, analyzer_target_data->azimuth, analyzer_target_data->elevation, analyzer_target_data->distance, analyzer_target_data->size_horizontal, analyzer_target_data->size_vertical, analyzer_target_data->x, analyzer_target_data->y, analyzer_target_data->z, analyzer_target_data->vx, analyzer_target_data->vy, analyzer_target_data->vz);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA, (const char *)analyzer_target_data, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_analyzer_target_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_status, uint32_t target_global_id, uint32_t target_local_id, uint32_t target_source_id, uint64_t timestamp, uint8_t confidence, uint8_t target_type, float azimuth, float elevation, float distance, float size_horizontal, float size_vertical, float x, float y, float z, float vx, float vy, float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, target_global_id);
    _mav_put_uint32_t(buf, 12, target_local_id);
    _mav_put_uint32_t(buf, 16, target_source_id);
    _mav_put_float(buf, 20, azimuth);
    _mav_put_float(buf, 24, elevation);
    _mav_put_float(buf, 28, distance);
    _mav_put_float(buf, 32, size_horizontal);
    _mav_put_float(buf, 36, size_vertical);
    _mav_put_float(buf, 40, x);
    _mav_put_float(buf, 44, y);
    _mav_put_float(buf, 48, z);
    _mav_put_float(buf, 52, vx);
    _mav_put_float(buf, 56, vy);
    _mav_put_float(buf, 60, vz);
    _mav_put_uint8_t(buf, 64, target_status);
    _mav_put_uint8_t(buf, 65, confidence);
    _mav_put_uint8_t(buf, 66, target_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA, buf, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_CRC);
#else
    mavlink_analyzer_target_data_t *packet = (mavlink_analyzer_target_data_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->target_global_id = target_global_id;
    packet->target_local_id = target_local_id;
    packet->target_source_id = target_source_id;
    packet->azimuth = azimuth;
    packet->elevation = elevation;
    packet->distance = distance;
    packet->size_horizontal = size_horizontal;
    packet->size_vertical = size_vertical;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->vx = vx;
    packet->vy = vy;
    packet->vz = vz;
    packet->target_status = target_status;
    packet->confidence = confidence;
    packet->target_type = target_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA, (const char *)packet, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE ANALYZER_TARGET_DATA UNPACKING


/**
 * @brief Get field target_status from analyzer_target_data message
 *
 * @return  Target status
 */
static inline uint8_t mavlink_msg_analyzer_target_data_get_target_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  64);
}

/**
 * @brief Get field target_global_id from analyzer_target_data message
 *
 * @return  Target Global ID
 */
static inline uint32_t mavlink_msg_analyzer_target_data_get_target_global_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field target_local_id from analyzer_target_data message
 *
 * @return  Target Local ID. (if target not from local source than LocalID=GlobalID)
 */
static inline uint32_t mavlink_msg_analyzer_target_data_get_target_local_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field target_source_id from analyzer_target_data message
 *
 * @return  Target source ID
 */
static inline uint32_t mavlink_msg_analyzer_target_data_get_target_source_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field timestamp from analyzer_target_data message
 *
 * @return [us] Timestamp in microseconds
 */
static inline uint64_t mavlink_msg_analyzer_target_data_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field confidence from analyzer_target_data message
 *
 * @return [%] Confidence in percents [0..100]
 */
static inline uint8_t mavlink_msg_analyzer_target_data_get_confidence(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  65);
}

/**
 * @brief Get field target_type from analyzer_target_data message
 *
 * @return  Type of target
 */
static inline uint8_t mavlink_msg_analyzer_target_data_get_target_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  66);
}

/**
 * @brief Get field azimuth from analyzer_target_data message
 *
 * @return [deg] Target azimuth
 */
static inline float mavlink_msg_analyzer_target_data_get_azimuth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field elevation from analyzer_target_data message
 *
 * @return [deg] Target elevation
 */
static inline float mavlink_msg_analyzer_target_data_get_elevation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field distance from analyzer_target_data message
 *
 * @return [m] Target distance
 */
static inline float mavlink_msg_analyzer_target_data_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field size_horizontal from analyzer_target_data message
 *
 * @return [deg] Target horizontal size
 */
static inline float mavlink_msg_analyzer_target_data_get_size_horizontal(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field size_vertical from analyzer_target_data message
 *
 * @return [deg] Target vertical size
 */
static inline float mavlink_msg_analyzer_target_data_get_size_vertical(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field x from analyzer_target_data message
 *
 * @return [m] Target world space position coordinate X. In meters
 */
static inline float mavlink_msg_analyzer_target_data_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field y from analyzer_target_data message
 *
 * @return [m] Target world space position coordinate Y. In meters
 */
static inline float mavlink_msg_analyzer_target_data_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field z from analyzer_target_data message
 *
 * @return [m] Target world space position coordinate Z. In meters
 */
static inline float mavlink_msg_analyzer_target_data_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field vx from analyzer_target_data message
 *
 * @return [m/s] Target world space velocity along X axis. In meters per second
 */
static inline float mavlink_msg_analyzer_target_data_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field vy from analyzer_target_data message
 *
 * @return [m/s] Target world space velocity along Y axis. In meters per second
 */
static inline float mavlink_msg_analyzer_target_data_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field vz from analyzer_target_data message
 *
 * @return [m/s] Target world space velocity along Z axis. In meters per second
 */
static inline float mavlink_msg_analyzer_target_data_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Decode a analyzer_target_data message into a struct
 *
 * @param msg The message to decode
 * @param analyzer_target_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_analyzer_target_data_decode(const mavlink_message_t* msg, mavlink_analyzer_target_data_t* analyzer_target_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    analyzer_target_data->timestamp = mavlink_msg_analyzer_target_data_get_timestamp(msg);
    analyzer_target_data->target_global_id = mavlink_msg_analyzer_target_data_get_target_global_id(msg);
    analyzer_target_data->target_local_id = mavlink_msg_analyzer_target_data_get_target_local_id(msg);
    analyzer_target_data->target_source_id = mavlink_msg_analyzer_target_data_get_target_source_id(msg);
    analyzer_target_data->azimuth = mavlink_msg_analyzer_target_data_get_azimuth(msg);
    analyzer_target_data->elevation = mavlink_msg_analyzer_target_data_get_elevation(msg);
    analyzer_target_data->distance = mavlink_msg_analyzer_target_data_get_distance(msg);
    analyzer_target_data->size_horizontal = mavlink_msg_analyzer_target_data_get_size_horizontal(msg);
    analyzer_target_data->size_vertical = mavlink_msg_analyzer_target_data_get_size_vertical(msg);
    analyzer_target_data->x = mavlink_msg_analyzer_target_data_get_x(msg);
    analyzer_target_data->y = mavlink_msg_analyzer_target_data_get_y(msg);
    analyzer_target_data->z = mavlink_msg_analyzer_target_data_get_z(msg);
    analyzer_target_data->vx = mavlink_msg_analyzer_target_data_get_vx(msg);
    analyzer_target_data->vy = mavlink_msg_analyzer_target_data_get_vy(msg);
    analyzer_target_data->vz = mavlink_msg_analyzer_target_data_get_vz(msg);
    analyzer_target_data->target_status = mavlink_msg_analyzer_target_data_get_target_status(msg);
    analyzer_target_data->confidence = mavlink_msg_analyzer_target_data_get_confidence(msg);
    analyzer_target_data->target_type = mavlink_msg_analyzer_target_data_get_target_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN? msg->len : MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN;
        memset(analyzer_target_data, 0, MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_LEN);
    memcpy(analyzer_target_data, _MAV_PAYLOAD(msg), len);
#endif
}
