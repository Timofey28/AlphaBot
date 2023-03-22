#include "Detector.h"
#include <tuple>
using namespace std;

// -------- Strategy1 ---------------------------
pair<float, float> Strategy1::getHumanCoords()
{
    // �������
    return {0.0f, 0.0f};
}

tuple<float, float, float> Strategy1::getRobotCoords()
{
    // �������
    return make_tuple(0.0f, 0.0f, 0.0f);
}

pair<float, float> Strategy1::getDispenserCoords()
{
    // �������
    return {0.0f, 0.0f};
}
// ----------------------------------------------

// -------- Strategy2 ---------------------------
pair<float, float> Strategy2::getHumanCoords()
{
    // �������
    return {2.0f, 2.0f};
}

tuple<float, float, float> Strategy2::getRobotCoords()
{
    // �������
    return make_tuple(2.0f, 2.0f, 2.0f);
}

pair<float, float> Strategy2::getDispenserCoords()
{
    // �������
    return {2.0f, 2.0f};
}
// ----------------------------------------------
