#ifndef SYSTEM_H
#define SYSTEM_H
#include "Dispenser.h"
#include "Dispenser.cpp"
#include "Robot.h"
#include "Robot.cpp"

enum EState {eWork, eTravel, ePour, eTravelBack, eCalm};

class System
{
    EState eState;
    float humanPos_x, humanPos_y;
    Robot* robot;
    Dispenser* dispenser;
public:
    System();
    ~System();
    void processEvent();
    int getDrink();
    void getHumanCoords();
    void getRobotCoords();
    void getDispenserCoords();
    bool robotArrived(std::pair<float, float> dest, int accuracy = 1);
};

#endif // SYSTEM_H
