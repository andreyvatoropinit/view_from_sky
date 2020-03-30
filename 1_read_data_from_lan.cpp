#include "1_read_data_from_lan.h"

#include "mavlink.h"
#include "target_analyzer/mavlink_msg_analyzer_target_data.h"

#include "2_controller.h"

AppCore::AppCore(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);

    socket->bind(QHostAddress::LocalHost, qgroundport);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

ONE_FRAME ClearFrame (ONE_FRAME one_frame)
{
    memset(&one_frame.car,0,sizeof (one_frame.car));
    memset(&one_frame.way_looking,0,sizeof (one_frame.way_looking));
    one_frame.objects.clear();
    return one_frame;
}

void ReadDataFromGPS ()
{

}

void AppCore::readyRead()
{
    ReadDataFromGPS ();

    QByteArray buffer{};
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    mavlink_message_t message {}; mavlink_status_t status {};

    for (int pos = 0; pos < buffer.length(); ++pos)
    {
       if (!mavlink_parse_char(0, (uint8_t)buffer[pos], &message, &status))
           continue;
    }

    mavlink_analyzer_target_data_t analyzer_target_data {};
    mavlink_msg_analyzer_target_data_decode(&message, &analyzer_target_data);

    static ONE_FRAME one_frame{};

    if (analyzer_target_data.target_global_id == 0)
        return;

    if (analyzer_target_data.target_global_id == target_global_id_car)
    {
        OBJECT_ON_IKO car {};
        car.target_global_id = target_global_id_car;
        car.latitude = analyzer_target_data.y;
        car.longitude = analyzer_target_data.x;
        one_frame.car = car;
    }
    else if (analyzer_target_data.target_global_id == target_global_way_of_looking)
    {
        OBJECT_ON_IKO way_looking {};
        way_looking.target_global_id = target_global_way_of_looking;
        way_looking.latitude = analyzer_target_data.y;
        way_looking.longitude = analyzer_target_data.x;
        one_frame.way_looking = way_looking;
    }
    else if (analyzer_target_data.target_global_id > target_global_way_of_looking && analyzer_target_data.target_global_id != flag_that_all_targets_in_one_frame_sended)
    {
        OBJECT_ON_IKO one_object {};
        one_object.latitude = analyzer_target_data.y;
        one_object.longitude = analyzer_target_data.x;
        one_object.target_global_id = analyzer_target_data.target_global_id;
        one_object.azimuth = analyzer_target_data.azimuth;
        one_object.distance = analyzer_target_data.distance;
        one_frame.objects.push_back(one_object);
    }
    else if (analyzer_target_data.target_global_id == flag_that_all_targets_in_one_frame_sended)
    {
        InterFaceFromLanToController (one_frame);

        one_frame = ClearFrame (one_frame);
    }
}
