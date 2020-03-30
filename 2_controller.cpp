#include "2_controller.h"
#include "1_read_data_from_lan.h"

enum PRESSED_BUTTONS
{
    button_one,
    button_two
};

void  AppCore :: InterFaceFromLanToController (ONE_FRAME one_frame)
{
    int pressed_buttons = button_one;

    InterFaceFromControllerToModel (one_frame,pressed_buttons);
}

void AppCore::receiveFromQml(int a)
{
    qDebug() << "data from qml";
}
