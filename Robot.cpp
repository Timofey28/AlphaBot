#include "Robot.h"
using namespace std;

Robot::Robot()
{
    printf("\n������ ������ ������");
}

void Robot::turn(pair<float, float> destination)
{
    printf("\n����� ����������");
}

void Robot::go(pair<float, float> destination)
{
    printf("\n����� ������");
}

void Robot::setCoords(float _x, float _y, float _angle)
{
    x = _x;
    y = _y;
    angle = _angle;
}
