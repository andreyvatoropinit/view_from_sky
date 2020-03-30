QT -= gui
QT += network
QT += positioning

CONFIG += c++11 console
CONFIG -= app_bundle


TEMPLATE = app
TARGET = planespotter
QT += qml quick positioning positioning-private location

SOURCES += \
    0_main.cpp \
    1_read_data_from_lan.cpp \
    2_controller.cpp \
    3_model.cpp

RESOURCES += qml.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/location/planespotter
INSTALLS += target


HEADERS += \
    1_read_data_from_lan.h \
    2_controller.h \
    3_model.h \
    mavlink/include/checksum.h \
    mavlink/include/mavlink_conversions.h \
    mavlink/include/mavlink_get_info.h \
    mavlink/include/mavlink_helpers.h \
    mavlink/include/mavlink_sha256.h \
    mavlink/include/mavlink_types.h \
    mavlink/include/message.hpp \
    mavlink/include/microservice/mavlink.h \
    mavlink/include/microservice/mavlink_msg_microservice_command.h \
    mavlink/include/microservice/mavlink_msg_microservice_command.hpp \
    mavlink/include/microservice/mavlink_msg_microservice_heartbeat_data.h \
    mavlink/include/microservice/mavlink_msg_microservice_heartbeat_data.hpp \
    mavlink/include/microservice/mavlink_msg_microservice_request_data.h \
    mavlink/include/microservice/mavlink_msg_microservice_request_data.hpp \
    mavlink/include/microservice/microservice.h \
    mavlink/include/microservice/microservice.hpp \
    mavlink/include/microservice/testsuite.h \
    mavlink/include/microservice/version.h \
    mavlink/include/msgmap.hpp \
    mavlink/include/protocol.h \
    mavlink/include/target_analyzer/mavlink.h \
    mavlink/include/target_analyzer/mavlink_msg_analyzer_target_data.h \
    mavlink/include/target_analyzer/mavlink_msg_analyzer_target_data.hpp \
    mavlink/include/target_analyzer/target_analyzer.h \
    mavlink/include/target_analyzer/target_analyzer.hpp \
    mavlink/include/target_analyzer/testsuite.h \
    mavlink/include/target_analyzer/version.h

INCLUDEPATH += mavlink/include/
INCLUDEPATH += mavlink/include/microservice
INCLUDEPATH += mavlink/include/target_analyzer

DISTFILES +=

