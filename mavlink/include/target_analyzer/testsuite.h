/** @file
 *    @brief MAVLink comm protocol testsuite generated from target_analyzer.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef TARGET_ANALYZER_TESTSUITE_H
#define TARGET_ANALYZER_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_microservice(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_target_analyzer(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_microservice(system_id, component_id, last_msg);
    mavlink_test_target_analyzer(system_id, component_id, last_msg);
}
#endif

#include "../microservice/testsuite.h"


static void mavlink_test_analyzer_target_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ANALYZER_TARGET_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_analyzer_target_data_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,197,8,75
    };
    mavlink_analyzer_target_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.target_global_id = packet_in.target_global_id;
        packet1.target_local_id = packet_in.target_local_id;
        packet1.target_source_id = packet_in.target_source_id;
        packet1.azimuth = packet_in.azimuth;
        packet1.elevation = packet_in.elevation;
        packet1.distance = packet_in.distance;
        packet1.size_horizontal = packet_in.size_horizontal;
        packet1.size_vertical = packet_in.size_vertical;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.vx = packet_in.vx;
        packet1.vy = packet_in.vy;
        packet1.vz = packet_in.vz;
        packet1.target_status = packet_in.target_status;
        packet1.confidence = packet_in.confidence;
        packet1.target_type = packet_in.target_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ANALYZER_TARGET_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_analyzer_target_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_analyzer_target_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_analyzer_target_data_pack(system_id, component_id, &msg , packet1.target_status , packet1.target_global_id , packet1.target_local_id , packet1.target_source_id , packet1.timestamp , packet1.confidence , packet1.target_type , packet1.azimuth , packet1.elevation , packet1.distance , packet1.size_horizontal , packet1.size_vertical , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz );
    mavlink_msg_analyzer_target_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_analyzer_target_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_status , packet1.target_global_id , packet1.target_local_id , packet1.target_source_id , packet1.timestamp , packet1.confidence , packet1.target_type , packet1.azimuth , packet1.elevation , packet1.distance , packet1.size_horizontal , packet1.size_vertical , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz );
    mavlink_msg_analyzer_target_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_analyzer_target_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_analyzer_target_data_send(MAVLINK_COMM_1 , packet1.target_status , packet1.target_global_id , packet1.target_local_id , packet1.target_source_id , packet1.timestamp , packet1.confidence , packet1.target_type , packet1.azimuth , packet1.elevation , packet1.distance , packet1.size_horizontal , packet1.size_vertical , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz );
    mavlink_msg_analyzer_target_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_target_analyzer(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_analyzer_target_data(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TARGET_ANALYZER_TESTSUITE_H
