#include "System.h"
#include <memory>
#include <cmath>
using namespace std;

System::System()
{
    eState = eWork;
    robot = make_unique<Robot>();
    dispenser = make_unique<Dispenser>();
    detector = make_unique<Detector<Strategy>>();
}

void System::processEvent()
{
    pair<float, float> coords;
    tuple<float, float, float> robotCoords;
    switch(eState)
    {
        case eWork:
            getDrink();

            coords = detector->getHumanCoords();
            humanPos_x = coords.first;
            humanPos_y = coords.second;

            robotCoords = detector->getRobotCoords();
            robot->setCoords(get<0>(robotCoords), get<1>(robotCoords), get<2>(robotCoords));

            coords = detector->getDispenserCoords();
            dispenser->setCoords(coords.first, coords.second);

            eState = eTravel;
            break;
        case eTravel:
            robotCoords = detector->getRobotCoords();
            robot->setCoords(get<0>(robotCoords), get<1>(robotCoords), get<2>(robotCoords));

            coords = dispenser->getCoords();
            if(robotArrived(coords))
                eState = ePour;
            else {
                robot->turn(coords);
                robot->go(coords);
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

void System::getDrink()
{
    int drink = 1;
    dispenser->setDrink(drink);
}

bool System::robotArrived(pair<float, float> dest, int accuracy)  // округление до <accuracy> знаков после запятой
{
    accuracy = pow(10, accuracy);
    if(round(dest.first * accuracy) / accuracy == round(dest.first * accuracy) / accuracy &&
       round(dest.second * accuracy) / accuracy == round(dest.second * accuracy) / accuracy)
        return 1;
    else return 0;
}
