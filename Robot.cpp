#include "Robot.h"
#include <bits/stdc++.h>

Robot::Robot()
{
    printf("\n������ ������ ������");
}

void Robot::turn(std::pair<float, float> destination)
{
    printf("\n����� ����������");
}

void Robot::go(std::pair<float, float> destination)
{
    printf("\n����� ������");
}

void Robot::setCoords(float _x, float _y, float _angle)
{
    x = _x;
    y = _y;
    angle = _angle;
}
