#ifndef APP_CORE_H
#define APP_CORE_H

#include <QObject>
#include <qudpsocket.h>
#include <QTimer>

struct OBJECT_ON_IKO
{
    float latitude;
    float longitude;
    int target_global_id;
    float azimuth;
    float distance;
};

struct ONE_FRAME
{
    OBJECT_ON_IKO car;
    OBJECT_ON_IKO way_looking;
    QVector <OBJECT_ON_IKO> objects;
};


class AppCore : public QObject
{
    Q_OBJECT

    public:
    explicit AppCore(QObject *parent = 0);

    signals:
    void sendToQml(float car_lat, float car_lon, float way_lat, float way_lon, QString id);
    void sendToQml2  (float obj_first_lat, float obj_first_lon, float obj_second_lat, float obj_second_lon, QString id);
    void sendToQml3  (float obj_first_lat, float obj_first_lon, float obj_second_lat, float obj_second_lon, QString id);

    private:
    float car_lat;
    float car_lon;
    float way_lat;
    float way_lon;

    QString hostAddress = "127.0.0.1";
    qint16 qgroundport = 14550;

    private slots:
    void readyRead();
    void InterFaceFromLanToController (ONE_FRAME);
    void InterFaceFromControllerToModel (ONE_FRAME, int);
    void send_object_one (OBJECT_ON_IKO);
    void send_object_two (OBJECT_ON_IKO);

    public slots:
    void receiveFromQml(int count);
   // void send_object_free (ONE_FRAME);
   // void send_object_four (ONE_FRAME);
   // void send_object_five (ONE_FRAME);

    private:
    QUdpSocket *socket;
};

static const int target_global_id_car = 1;
static const int target_global_way_of_looking = 2;
static const uint32_t flag_that_all_targets_in_one_frame_sended = UINT32_MAX;

#endif // APP_CORE_H
