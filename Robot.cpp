#include "Robot.h"
using namespace std;

Robot::Robot()
{
    printf("\nСоздан объект робота");
}

void Robot::turn(pair<float, float> destination)
{
    printf("\nРобот повернулся");
}

void Robot::go(pair<float, float> destination)
{
    printf("\nРобот поехал");
}

void Robot::setCoords(float _x, float _y, float _angle)
{
    x = _x;
    y = _y;
    angle = _angle;
}
