#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include "1_read_data_from_lan.h"

#include <QGeoCoordinate>

class PlaneController: public QObject
{
    signals:
    void sendToQml  (float car_lat, float car_lon, float way_lat, float way_lon, QString id);
    void sendToQml2  (float obj_first_lat, float obj_first_lon, float obj_second_lat, float obj_second_lon, QString id);
    void sendToQml3  (float obj_first_lat, float obj_first_lon, float obj_second_lat, float obj_second_lon, QString id);


};

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    PlaneController first2second{};
    PlaneController third2four{};
    PlaneController five2six{};

    QQmlApplicationEngine engine;

    AppCore appCore{};

    QQmlContext *context = engine.rootContext();

    context->setContextProperty("appCore", &appCore);

    engine.rootContext()->setContextProperty("first2second", &first2second);
    engine.rootContext()->setContextProperty("third2four", &third2four);
    engine.rootContext()->setContextProperty("five2six", &five2six);

    engine.load(QUrl(QStringLiteral("qrc:/planespotter.qml")));

    return app.exec();
}
