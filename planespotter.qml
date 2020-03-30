import QtQuick 2.4
import QtQuick.Window 2.2
import QtPositioning 5.5
import QtLocation 5.6
import QtQuick.Controls 1.4

Window {
    width: 1300
    height: 700
    visible: true

   property real offset_lat: 0.0


   property variant topLeftEurope: QtPositioning.coordinate(53.971658, 27.45845)
   property variant bottomRightEurope: QtPositioning.coordinate(53.822361, 27.967547)
   property variant viewOfEurope:
        QtPositioning.rectangle(topLeftEurope, bottomRightEurope)

   property variant first:  QtPositioning.coordinate  (0,  0)
   property variant second: QtPositioning.coordinate  (0,  0)

   property variant third:  QtPositioning.coordinate  (0,  0)
   property variant four:  QtPositioning.coordinate  (0,  0)

   property variant five:  QtPositioning.coordinate  (0,  0)
   property variant six:  QtPositioning.coordinate  (0,  0)

   property variant pilot_one_name_string: "pilot one"
   property variant pilot_two_name_string: "pilot two"

    Connections {
        target: appCore

        onSendToQml: {
            first = QtPositioning.coordinate  (car_lat, car_lon)
            second = QtPositioning.coordinate (way_lat, way_lon)

            coordinateAnimation.from = first;
            coordinateAnimation.to = second;
            qmlPlaneAnimation.rotationDirection = first2second.position.azimuthTo(coordinateAnimation.to)
            qmlPlaneAnimation.start()
        }
    }

    Connections {
        target: appCore

        onSendToQml2: {
                third = QtPositioning.coordinate (obj_first_lat, obj_first_lon)
                four = QtPositioning.coordinate  (obj_second_lat, obj_second_lon)

                coordinateAnimation_2.from = third;
                coordinateAnimation_2.to = four;
                qmlPlaneAnimation_2.rotationDirection = third2four.position.azimuthTo(coordinateAnimation_2.to)
                qmlPlaneAnimation_2.start()
                pilot_one_name_string = id;
        }
    }

    Connections {
        target: appCore

        onSendToQml3: {
                five = QtPositioning.coordinate (obj_first_lat, obj_first_lon)
                six = QtPositioning.coordinate  (obj_second_lat, obj_second_lon)

                coordinateAnimation_3.from = five;
                coordinateAnimation_3.to = six;
                qmlPlaneAnimation_3.rotationDirection = five2six.position.azimuthTo(coordinateAnimation_3.to)
                qmlPlaneAnimation_3.start()
                pilot_two_name_string = id;
        }
    }


    Map {
        id: mapOfEurope
        anchors.centerIn: parent;
        anchors.fill: parent
        plugin: Plugin {
            name: "osm" // "mapboxgl", "esri", ...
        }

        Button {
            text: "Button"
            onClicked: {
                title = "Button"

                appCore.receiveFromQml(42);
            }
        }

        Plane {
            id: qmlPlane
            pilotName: "car"
            coordinate: first2second.position = first

            SequentialAnimation {
                id: qmlPlaneAnimation
                property real rotationDirection : 0;
                NumberAnimation {
                    target: qmlPlane; property: "bearing"; duration: 1000
                    easing.type: Easing.InOutQuad
                    to: qmlPlaneAnimation.rotationDirection
                }
                CoordinateAnimation {
                    id: coordinateAnimation; duration: 1000
                    target: first2second; property: "position"
                    easing.type: Easing.InOutQuad
                }

            }

        }

        Plane {
            id: object_one
            pilotName: pilot_one_name_string
            coordinate: third2four.position = third

            SequentialAnimation {
                id: qmlPlaneAnimation_2
                property real rotationDirection : 0;
                NumberAnimation {
                    target: object_one; property: "bearing"; duration: 1000
                    easing.type: Easing.InOutQuad
                    to: qmlPlaneAnimation_2.rotationDirection
                }
                CoordinateAnimation {
                    id: coordinateAnimation_2; duration: 1000
                    target: third2four; property: "position"
                    easing.type: Easing.InOutQuad
                }

            }

        }

        Plane {
            id: object_two
            pilotName: pilot_two_name_string
            coordinate: five2six.position = five

            SequentialAnimation {
                id: qmlPlaneAnimation_3
                property real rotationDirection : 0;
                NumberAnimation {
                    target: object_two; property: "bearing"; duration: 1000
                    easing.type: Easing.InOutQuad
                    to: qmlPlaneAnimation_3.rotationDirection
                }
                CoordinateAnimation {
                    id: coordinateAnimation_3; duration: 1000
                    target: third2four; property: "position"
                    easing.type: Easing.InOutQuad
                }

            }

        }
        visibleRegion: viewOfEurope
    }
}
