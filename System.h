#ifndef SYSTEM_H
#define SYSTEM_H
#include "Dispenser.h"
#include "Dispenser.cpp"
#include "Robot.h"
#include "Robot.cpp"
#include "Detector.h"
#include "Detector.cpp"
#include <memory>
typedef Strategy1 Strategy; // вид реализации функций вы€влени€ объектов на кадре

enum EState {eWork, eTravel, ePour, eTravelBack, eCalm};

class System
{
    EState eState;
    float humanPos_x, humanPos_y;
    std::unique_ptr<Robot> robot;
    std::unique_ptr<Dispenser> dispenser;
    std::unique_ptr<Detector<Strategy>> detector;
public:
    System();
    void processEvent();
    void getDrink();
    bool robotArrived(std::pair<float, float> dest, int accuracy = 1); // с точностью до accuracy знаков после зап€той
};

#endif // SYSTEM_H
