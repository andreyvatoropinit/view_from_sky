#include <QGeoCoordinate>
#include "QtMath"
#include "1_read_data_from_lan.h"
#include "3_model.h"

ONE_FRAME ConvertFromXYZtoLatLonView (ONE_FRAME one_frame)
{
    for (int i = 0; i < one_frame.objects.size();i++)
    {
        QGeoCoordinate pozition_one_object_lat_lon_view{};

        pozition_one_object_lat_lon_view.setLatitude(one_frame.car.latitude);
        pozition_one_object_lat_lon_view.setLongitude(one_frame.car.longitude);

        pozition_one_object_lat_lon_view = pozition_one_object_lat_lon_view.atDistanceAndAzimuth(one_frame.objects[i].distance, one_frame.objects[i].azimuth,0);

        float latitide = pozition_one_object_lat_lon_view.latitude();
        float longitude  = pozition_one_object_lat_lon_view.longitude();

        one_frame.objects[i].latitude = latitide;
        one_frame.objects[i].longitude = longitude;
    }

    return one_frame;
}

bool CheckAllObjectHaveId (ONE_FRAME one_frame)
{
    if (one_frame.car.target_global_id == 0) return false;
    if (one_frame.way_looking.target_global_id == 0) return false;

    for (int i = 0; i < one_frame.objects.size(); i++)
    {
        if (one_frame.objects[i].target_global_id == 0) return false;
    }

    return true;
}

void  AppCore :: send_object_two (OBJECT_ON_IKO object)
{
    static int count_times_join{};

    static float lat_object_first_pozition{};
    static float lon_object_first_pozition{};

    float lat_object_second_pozition{};
    float lon_object_second_pozition{};

    if (count_times_join == first_time_join_in_function)
    {
        lat_object_first_pozition = object.latitude;
        lon_object_first_pozition = object.longitude;
        count_times_join = second_time_join_in_function;
    }
    else if (count_times_join == second_time_join_in_function)
    {
        lat_object_second_pozition = object.latitude;
        lon_object_second_pozition = object.longitude;
        emit sendToQml3  (lat_object_first_pozition, lon_object_first_pozition, lat_object_second_pozition, lon_object_second_pozition, ("id " + QString::number(object.target_global_id)));
        count_times_join = first_time_join_in_function;

        lat_object_first_pozition = lon_object_first_pozition = lon_object_second_pozition = lat_object_second_pozition = 0;
    }
}

void  AppCore :: send_object_one (OBJECT_ON_IKO object)
{
    static int count_times_join{};

    static float lat_object_first_pozition{};
    static float lon_object_first_pozition{};

    float lat_object_second_pozition{};
    float lon_object_second_pozition{};

    if (count_times_join == first_time_join_in_function)
    {
        lat_object_first_pozition = object.latitude;
        lon_object_first_pozition = object.longitude;
        count_times_join = second_time_join_in_function;
    }
    else if (count_times_join == second_time_join_in_function)
    {
        lat_object_second_pozition = object.latitude;
        lon_object_second_pozition = object.longitude;
        emit sendToQml2  (lat_object_first_pozition, lon_object_first_pozition, lat_object_second_pozition, lon_object_second_pozition, ("id " + QString::number(object.target_global_id)));
        count_times_join = first_time_join_in_function;

        lat_object_first_pozition = lon_object_first_pozition = lon_object_second_pozition = lat_object_second_pozition = 0;
    }
}

void  AppCore :: InterFaceFromControllerToModel (ONE_FRAME one_frame, int pressed_button)
{
    one_frame = ConvertFromXYZtoLatLonView (one_frame);

    bool each_object_have_id  = CheckAllObjectHaveId(one_frame);

    if (each_object_have_id == false) return;

    static bool flag_only_one_time = true;

    if (flag_only_one_time == true)
    {
        flag_only_one_time = false;
        emit sendToQml(one_frame.car.latitude, one_frame.car.longitude, one_frame.way_looking.latitude, one_frame.way_looking.longitude, "car");
    }

    QVector <OBJECT_ON_IKO> objects {}; objects = one_frame.objects;

    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i].target_global_id == target_global_object_one)
        {
            AppCore :: send_object_one ( objects[i]);
        }
        else if (objects[i].target_global_id == target_global_object_two)
        {
            AppCore :: send_object_two ( objects[i]);
        }
    }
}
