#include "System.h"
#include <bits/stdc++.h>

System::System()
{
    eState = eWork;
    robot = new Robot();
    dispenser = new Dispenser();
}

System::~System()
{
    delete robot;
    delete dispenser;
}

void System::processEvent()
{
    switch(eState)
    {
        case eWork:
            getDrink();
            getHumanCoords();
            getRobotCoords();
            getDispenserCoords();
            eState = eTravel;
            break;
        case eTravel:
            getRobotCoords();
            if(robotArrived(dispenser->getCoords()))
                eState = ePour;
            else {
                robot->turn(dispenser->getCoords());
                robot->go(dispenser->getCoords());
            }
            break;
        case ePour:
            dispenser->pourDrink(dispenser->getDrink());
            eState = eTravelBack;
            break;
        case eTravelBack:
            if(robotArrived({humanPos_x, humanPos_y}))
                eState = eCalm;
            else {
                robot->turn({humanPos_x, humanPos_y});
                robot->go({humanPos_x, humanPos_y});
            }
            break;
        default: break;
    }
}

int System::getDrink()
{
    int drink = 1;
    dispenser->setDrink(drink);
}

void System::getHumanCoords()
{
    humanPos_x = 0.0f;
    humanPos_y = 0.0f;
}

void System::getRobotCoords()
{
    float x = 0.0f;
    float y = 0.0f;
    float angle = 0.0f;
    robot->setCoords(x, y, angle);
}

void System::getDispenserCoords()
{
    float x = 0.0f;
    float y = 0.0f;
    dispenser->setCoords(x, y);
}

bool System::robotArrived(std::pair<float, float> dest, int accuracy)  // округление до <accuracy> знаков после запятой
{
    accuracy = pow(10, accuracy);
    if(round(dest.first * accuracy) / accuracy == round(dest.first * accuracy) / accuracy &&
       round(dest.second * accuracy) / accuracy == round(dest.second * accuracy) / accuracy)
        return 1;
    else return 0;
}
